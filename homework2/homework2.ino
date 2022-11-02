#define STATE1 1 //when car are crossing
#define STATE2 2 // when the semaphore is yellow
#define STATE3 3 // when pedestrians are crossing the street
#define STATE4 4 // when pedestrians green light is blinking

const int state1Debounce = 8000;
const int state2Debounce = 3000;
const int state3Debounce = 8000;
const int state4Debounce = 4000;
int state = 1;
unsigned long debounceTime = 0;

const int buzzerPin = 11;
const int buttonPin = 2;

//initialize semaphore for pedestrians
const int pedRedPin = 8;
const int pedGreenPin = 9;

//initialize semaphore for cars
const int carRedPin= 5;
const int carYellowPin = 6;
const int carGreenPin = 7;

//functionalities for pedestrians's semaphor 
const int buzzerSound = 500;
const int buzzerSoundState3 = 250;
const int buzzTimeDebounce = 250;
const int buzzFastTimeDebounce = 250;
const int blinkTimeDebounce = 500;
int blinkValue = LOW;
unsigned long lastBuzz = 0;
unsigned long lastBlink = 0;

//functionalities for button
int reading = 0;
bool buttonPressed = 0;
bool lastButtonState = LOW;
bool buttonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);
  
  pinMode(carRedPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);
  
  Serial.begin(9600);  
}

void loop() {
   buttonCheck();
   manageStates();
   chooseState();
}

void state1() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, HIGH);
  noTone(buzzerPin);    
}

void state2() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(carYellowPin, HIGH);
  digitalWrite(carGreenPin, LOW);
  noTone(buzzerPin);    
}

void state3() {
  digitalWrite(pedRedPin, LOW);
  digitalWrite(pedGreenPin, HIGH);
  digitalWrite(carRedPin, HIGH);
  digitalWrite(carRedPin, HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, LOW);
  if (millis() - lastBuzz > buzzTimeDebounce) {
    noTone(buzzerPin);
  } 
  if (millis() - lastBuzz > 2 * buzzTimeDebounce) {
    tone(buzzerPin, buzzerSoundState3);
    lastBuzz = millis();
  } 
}

void state4() {
  digitalWrite(pedRedPin, LOW);
  // blink checker
  if (millis() - lastBlink > blinkTimeDebounce) {
    blinkValue = !blinkValue;
    lastBlink = millis();
  }
  digitalWrite(pedGreenPin, blinkValue);
  digitalWrite(carRedPin, HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, LOW);

  if (millis() - lastBuzz > buzzFastTimeDebounce) {
    noTone(buzzerPin);
  }
  if (millis() - lastBuzz > 2 * buzzFastTimeDebounce) {
    tone(buzzerPin, buzzerSound);
    lastBuzz = millis();
  }  
}

void buttonCheck() { 
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW && state == 1) {
        if (!buttonPressed) { // to not reset the timer if the button is pressed multiple times
          buttonPressed = 1;
          debounceTime = millis();
        }
      }
    }
  }
  lastButtonState = reading;
}

void manageStates() {
    if(state == STATE1 && millis() - debounceTime > state1Debounce && buttonPressed ){
      state = STATE2;
      debounceTime = millis();
      buttonPressed = 0;
    } 
    else
      if(state == STATE2 && millis() - debounceTime > state2Debounce ){
        state = STATE3;
        debounceTime = millis();
      }
      else
        if(state == STATE3 && millis() - debounceTime > state3Debounce ){
          state = STATE4;
          debounceTime = millis();
        }
        else
          if(state == STATE4 && millis() - debounceTime > state4Debounce){
            state = STATE1;
            debounceTime = millis();
            
      }
}

void chooseState(){
  if (state == STATE1) {
      state1();
  } 
  else 
    if (state == STATE2) {
        state2();
    } 
    else  
      if (state == STATE3) {
        state3();
    } 
    else  
      if (state == STATE4) {
        state4();
    }
}

