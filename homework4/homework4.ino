#include <EEPROM.h>

// shift register pins
const int dataPin = 12; // DS
const int latchPin = 11; // STCP
const int clockPin = 10; // SHCP

// joystick pins
const int pinSW = 2;
const int pinX = A0;
const int pinY = A1;

// const for joystick
  // for mappings (check if the joystick moved)
const int minThreshold = 350;
const int maxThreshold = 700;

// digital point delay
const int dpDelay = 500;
const int minDigit = 0;
const int maxDigit = 15;

// const for interrupt debounce
const int interruptDelay = 200;

// values for joystick
volatile boolean state = false; // false = state 1; true = state 2

int xValue = 0;
int yValue = 0;
bool joyXMoved = false;
bool joyYMoved = false;

// values for display
int digits[4] = {0, 0, 0, 0};
bool points[4] = {0, 0, 0, 0};
int currentDisplay = 0;

// timer for digital point
long lastDpTime = 0;

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int displayCount = 3;

const int displayDigits[] = {
  segD1, segD2, segD3, segD4
};

int digitArray[16] = {
//A B C D E F G DP 
  B11111100, // 0 
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // B
  B10011100, // C
  B01111010, // D
  B10011110, // E
  B10001110  // F
};

bool reading = 0;
bool lastButtonState = 0;
unsigned long lastDebounceTimePressed = 0; 
bool lastReading = 0;
bool buttonPressed = 0;
unsigned long longPressedTime = 0;
const int longDebounceTimePressLong = 3000;
bool buttonState = 0;
bool buttonPressedState = 0;
unsigned long lasDebounceTimePressed = 0 ;
const int debounceDelayPressed = 50;
void setup() {
  // shift register
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // joystick button 
  pinMode(pinSW, INPUT_PULLUP);
  // interrupt when button is pressed
 
  // joystick axes
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);

  // 4-digit 7 segment display
  for (int i = 0; i <= displayCount; ++i) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW);
   }

  readEEPROM();
  Serial.begin(9600);
}
void loop() {
  buttonCheck();
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  if (!buttonPressed) {
    state1();
  } 
  else { 
    state2();  
  }
  Serial.println(state);
  writeDigits();
}
// function to read last value from EEPROM
void readEEPROM () {
  for (int i = 0; i <= displayCount; ++i) {
    digits[i] = EEPROM.read(i);
  }
}

// function to select only one display
void showDigit(int digit) {
  for (int i = 0; i <= displayCount; ++i) {
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[digit], LOW);
}

// function to write digit and digital point to shift register
void writeReg(int digit, int dpState) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit + dpState);
  digitalWrite(latchPin, HIGH);
}

// function to write digits to 4-segment
void writeDigits() {
  for (int i = 0; i <= displayCount; ++i) {
    showDigit(i);
    writeReg(digitArray[digits[i]], points[i]);
    EEPROM.update(i, digits[i]);
  
    delay(3);
  }
}
void resetDigits() {
  for(int i=0; i<=displayCount; ++i){
      digits[i]=0;
      points[i]=0; 
  }
  points[currentDisplay] = 1;

}

void blinkPoint(){ 
  if (millis() - lastDpTime > dpDelay) { // blinking digital point
      points[currentDisplay] = !points[currentDisplay];
      lastDpTime = millis();
  }
}

void state1(){
  if (xValue < minThreshold && !joyXMoved) { // if the joystick moved to the left
      if (currentDisplay < displayCount) { // and we have more displays to the lef
        points[currentDisplay] = false; // we change de digital point state
        ++currentDisplay; // change current display
      }
      joyXMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (xValue > maxThreshold && !joyXMoved) { // analog but to the right
      if (currentDisplay > 0) {
        points[currentDisplay] = false;
        --currentDisplay;
      }
      joyXMoved = true;
  }
  if (xValue > minThreshold && xValue < maxThreshold) { // reset joystick X movement
      joyXMoved = false;
    }
    blinkPoint();
  
}


void state2(){
  points[currentDisplay] = true; // activate the digital point to the current digit
    // for y axis 0 is max upward and 1023 is max downward
    if (yValue < minThreshold && !joyYMoved) { // if the joystick moved upward
      if (digits[currentDisplay] < maxDigit) { 
        ++digits[currentDisplay]; // increment
      }
      joyYMoved = true; 
    } 
    if (yValue > maxThreshold && !joyYMoved) {
      if (digits[currentDisplay] > minDigit) {
        --digits[currentDisplay];
      }
      joyYMoved = true;
    }
    if (yValue > minThreshold && yValue < maxThreshold) { // reset joystick Y movement
      joyYMoved = false;
    }
}

void buttonCheck() { 
  reading = digitalRead(pinSW);
  if (reading != lastButtonState) {
    lastDebounceTimePressed = millis();
  }

  if(buttonState == 0){
    if(reading!=lastReading){
      longPressedTime = millis();  
    }
    lastReading = reading;
    //reseted
    if(millis()-longPressedTime > longDebounceTimePressLong ){
      buttonPressed = 0;
      longPressedTime = millis();
      currentDisplay = 0;
      resetDigits();
      //Serial.println("Reseted");
    }
  }
 
  if (millis() - lastDebounceTimePressed > debounceDelayPressed) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW ) {
        if (!buttonPressed) { // to not reset the timer if the button is pressed multiple times
          buttonPressed = 1;
          
        }
        else{
          buttonPressed = 0;    
        }
      }  
    }
  }
  lastButtonState = reading;      
  }
