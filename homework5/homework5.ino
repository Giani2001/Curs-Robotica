#include <LiquidCrystal.h>
#include "LedControl.h"
const byte dinPin = 12;
const byte clockPin = 13;
const byte loadPin = 10;
int playIndex = 0;
LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);
const byte RS = 9;
const byte enable = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
int settingIndex = 0; 
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);
const int debounceTotalScroll = 400;
const int debounceTotal = 400;
const int debounceTotal2 = 200;
int contorFour = 0;
unsigned long scrollDebounce = 0;
unsigned long scrollDebounceFour = 0;
const int debounceIntro = 3000;
int menuIndex = 0; 
const int menuSize = 5;
int brightMat = 0;
const String menu[menuSize] = {"Play Game ", "Highscore ", "Settings ", "About ", "How To Play"};

const int pinSW = 2;
const int pinX = A1;
const int pinY = A0;

int contrastValue = 100;
bool joyXMoved = false;
bool joyYMoved = false;
const int minThresHold = 0;
const int maxThresHold = 150;
int xValue = 0;
int yValue = 0;
unsigned long lastDebounceTimeMovement = 0;
const int debounceTimeMovement = 1000;
int debounceValue = -1;
int length = 0;
int contor = 0; 
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
const String firstRowAbout = "Enjoy Game! ";
const String secondRowAbout = "Git:Giani2001 ";
unsigned long lastAboutDebounce = 0 ;
const int debounceAbout = 200;
int controlFour = 0; 
const String firstRowHow="How To Play!";
const String secondRowHow="Move the joystick UP and DOWN to not go into an obstacle!";


const int matrixBrightnessPin = 11;
const int lcdContrastPin = 3;
int constLCD = 126;
unsigned long lastDebounceTotal = 0;


const int xPin = A1;
const int yPin = A0;



byte matrixBrightness = 2;

byte xPos = 0;
byte yPos = 0;
byte xLastPos = 0;
byte yLastPos = 0;
byte xFood = random(8);
byte yFood = random(8);
const int minThreshold = 0;
const int maxThreshold = 150;
int score = 0;
const byte moveInterval = 100;
unsigned long long lastMoved = 0;

const byte matrixSize = 8;
bool matrixChanged = true;

byte matrix[matrixSize][matrixSize] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}  
};

byte matrixByte[matrixSize] = {
  B00000000,
  B01000100,
  B00101000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
  B00000000
};

void setup() {
// set up the LCD's number of columns and rows:

pinMode(pinX, OUTPUT);
pinMode(pinY, OUTPUT);
pinMode(pinSW, INPUT_PULLUP);
pinMode(matrixBrightnessPin, OUTPUT);
pinMode(lcdContrastPin, OUTPUT);
analogWrite(lcdContrastPin, contrastValue);
analogWrite(matrixBrightnessPin, constLCD);
lcd.begin(16, 2);
 matrix[xPos][yPos] = 1;
  matrix[xFood][yFood] = 1;
Serial.begin(9600);

}
void loop() {
   
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  Serial.println(yValue);
 
  if(millis() < debounceIntro){
    //delay(50);
    lcd.setCursor(0, 0);
    lcd.print("Welcome to the");
    lcd.setCursor(5,1);
    lcd.print("best game !");
  }
  else{
   
     buttonCheck();
    navigateIntoMenu();
    moveToMenu();
   
  
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
void moveToMenu()
{
  if (yValue < minThresHold && !joyYMoved) { // if the joystick moved to the left
      if(menuIndex > -1){
        --menuIndex;
        menuIndex = menuIndex%5;
      }
      
      
      joyYMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (yValue > maxThresHold && !joyYMoved) { // analog but to the right
      if( menuIndex <menuSize){
        ++menuIndex;
        menuIndex=menuIndex%5;
      }
      
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold) { // reset joystick X movement
      joyYMoved = false;
    }
}

void setMatrixContrast(){
  if (xValue < minThresHold && !joyXMoved && settingIndex ==0) { // if the joystick moved to the left
      if(brightMat > 0){
        brightMat =( brightMat - 3 )%15;
      }
      
      
      joyXMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex ==0) { // analog but to the right
      if( brightMat <15){
          brightMat = (brightMat + 3)%15;
      }
      
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex ==0) { // reset joystick X movement
      joyXMoved = false;
    }
}

void setLCDContrast(){
  if (xValue < minThresHold && !joyXMoved && settingIndex ==1) { // if the joystick moved to the left
      if(constLCD > 0){
        constLCD  =( constLCD  - 3 )%255;
      }
      
      
      joyXMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex ==1) { // analog but to the right
      if( constLCD <255){
           constLCD  =( constLCD  + 3 )%255;
           if(constLCD <115){
             constLCD = 115;
           }
      }
      
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex ==1) { // reset joystick X movement
      joyXMoved = false;
    }
}

void setLCDBrightness(){
  if (xValue < minThresHold && !joyXMoved && settingIndex ==2) { // if the joystick moved to the left
      if(contrastValue > 0){
        contrastValue  = (contrastValue  - 10)%500; 
      }
      
      
      joyXMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex ==2) { // analog but to the right
      if( contrastValue <500){
           contrastValue  = (contrastValue  + 10)%500 ;
      }
      
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex ==2) { // reset joystick X movement
      joyXMoved = false;
    }
}

void firstMenu(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[0]);
    lcd.setCursor(1,1);
    lcd.print(menu[1]);
}

void secondMenu(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[1]);
    lcd.setCursor(1,1);
    lcd.print(menu[2]);
}

void thirdMenu(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[2]);
    lcd.setCursor(1,1);
    lcd.print(menu[3]);
}

void fourthMenu(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[3]);
    lcd.setCursor(1,1);
    lcd.print(menu[4]);
}

void fifthMenu(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[4]);
    lcd.setCursor(1,1);
    lcd.print(menu[0]);
}
void matrixSet(){
    lcd.clear();
    setMatrixContrast();
    lcd.setCursor(3,0);
    lcd.print("Led Brightness");
    lcd.setCursor(3,1);
    lcd.print("<");
    lcd.setCursor(7,1);
    lcd.print(brightMat);
    lc.shutdown(0, false);
    lc.setIntensity(0,brightMat);
    lc.clearDisplay(0);
    lc.setLed(0, 3, 3, true);
    lcd.setCursor(12,1);  
    lcd.print(">");  
}

void lcdContrastSet(){
    lcd.clear();
    setLCDContrast();
    lcd.setCursor(3,0);
    lcd.print("LCD Contrast");
    lcd.setCursor(3,1);
    lcd.print("<");
    lcd.setCursor(7,1);
    lcd.print(constLCD);
    analogWrite(matrixBrightnessPin,constLCD); 
    lcd.setCursor(12,1);  
    lcd.print(">");  
}

void lcdContrastBright(){
    lcd.clear();
    setLCDBrightness();
    lcd.setCursor(3,0);
    lcd.print("LCD Brightness");
    lcd.setCursor(3,1);
    lcd.print("<");
    lcd.setCursor(7,1);
    lcd.print(setPotValue(contrastValue));
    analogWrite(lcdContrastPin, setPotValue(contrastValue));
    lcd.setCursor(12,1);  
    lcd.print(">");  
}

void moveToSetting()
{
  if (yValue < minThresHold && !joyYMoved && buttonPressed) { // if the joystick moved to the left
      if(settingIndex > -1){
        --settingIndex;
        settingIndex = settingIndex%3;
      }
      
      
      joyYMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (yValue > maxThresHold && !joyYMoved && buttonPressed) { // analog but to the right
      if( settingIndex <3){
         ++settingIndex;
        settingIndex = settingIndex%3;
      }
      
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold && buttonPressed) { // reset joystick X movement
      joyYMoved = false;
    }
}

void moveToPlay()
{
  if (yValue < minThresHold && !joyYMoved && buttonPressed) { // if the joystick moved to the left
      if(playIndex > -1){
        --playIndex;
        playIndex = playIndex%1;
      }
      
      
      joyYMoved = true; // boolean to increment the value for each movement (not continuosly)
    } 
  if (yValue > maxThresHold && !joyYMoved && buttonPressed) { // analog but to the right
      if( playIndex <1){
         ++playIndex;
        playIndex = playIndex%1;
      }
      
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold && buttonPressed) { // reset joystick X movement
      joyYMoved = false;
    }
}
void navigateIntoMenu(){
   blinkLeds();
  if(buttonPressed ==0){
    if(menuIndex == 0){
      if(millis()-lastDebounceTotal>debounceTotal){
      // Serial.println("zero");
      lastDebounceTotal= millis();
      firstMenu();
      }
    }
    else
      if(menuIndex == 1){
       if(millis()-lastDebounceTotal>debounceTotal){
          lastDebounceTotal= millis();
          secondMenu();
        }
      }
      else
        if(menuIndex == 2){
          if(millis()-lastDebounceTotal>debounceTotal2){
              lastDebounceTotal= millis();
              thirdMenu();
          }
        }
        else
          if(menuIndex==3){
           if(millis()-lastDebounceTotal>debounceTotal2){
              lastDebounceTotal= millis();
              fourthMenu();
            }
          }
          else
           if(menuIndex==4){
             if(millis()-lastDebounceTotal>debounceTotal2){
              lastDebounceTotal= millis();
              fifthMenu();
             }
           }
  }
  else
    if(menuIndex == 3){
      if(millis()-scrollDebounce > debounceTotalScroll){
      lcd.clear();
      lcd.setCursor(0,0);    
      length= firstRowAbout.length();
      lcd.print(firstRowAbout.substring(contor, contor + 16));
      lcd.print(firstRowAbout);
      lcd.setCursor(0,1);
      lcd.print(secondRowAbout);
      contor++;
      if(contor>(firstRowAbout.length()-16)){
        contor = 0;
      }
      scrollDebounce = millis();
      }
    }  
    else
      if(menuIndex == 4){
        if(millis()-scrollDebounceFour > debounceTotalScroll){
          lcd.clear();
          lcd.setCursor(0,0);    
          lcd.print(firstRowHow);
          lcd.setCursor(0,1);
          lcd.print(secondRowHow.substring(contorFour, contorFour + 16));
          contorFour++;
          if(contorFour>(secondRowHow.length()-16)){
            contorFour = 0;
        }
      scrollDebounceFour = millis();
      }

    }
      else
        if(menuIndex == 2){
           moveToSetting();
           if(settingIndex == 0){
             lc.setLed(0, 3, 3, true);
             if(millis()-lastDebounceTotal>debounceTotal2){
                lastDebounceTotal= millis();
                
                matrixSet();
            }              
           }
           else
              if(settingIndex ==1){
                 if(millis()-lastDebounceTotal>debounceTotal2){
                    lastDebounceTotal= millis();
                    lcdContrastSet();
                 } 
              }
              else
                 if(settingIndex ==2){
                  if(millis()-lastDebounceTotal>debounceTotal2){
                    lastDebounceTotal= millis();
                    lcdContrastBright();
                  } 
               
                 }
                

        }
        else
          if(menuIndex == 0 ){
            //   matrix[xPos][yPos] = 1;
            //   matrix[xFood][yFood] = 1;
            // lc.setLed(0, 3, 3, false);
            moveToPlay();
            if(playIndex == 0){
            playGAME();
             lcd.clear();
            lcd.setCursor(0,0);    
            lcd.print("Score:");
            lcd.setCursor (8,0);
            lcd.print(score);
          }
}
}
int setPotValue(int potValue){
  return map(potValue, 0, 1023, 0, 255);
}

void blinkLeds(){
    
    // if(settingIndex ==0 && buttonPressed){
    //   lc.setLed(0, 3, 3, true);
    // }
    // else
    //   lc.setLed(0, 3, 3, false);
    if(playIndex == 0 && buttonPressed){
        matrix[xPos][yPos] = 1;
    matrix[xFood][yFood] = 1;
     lc.setLed(0, 3, 3, false);
    }
    else
    { lc.setLed(0, xPos, yPos, false);
       lc.setLed(0, xFood, yFood, false);
       lc.setLed(0, 3, 3, false);
   // matrix[xPos][yPos] = 0;
   // matrix[xFood][yFood] = 0;
    }
}
void playGAME() {
//  updateByteMatrix();
  if (millis() - lastMoved > moveInterval) {
  // game logic
    updatePositions();
    lastMoved = millis();
  }
  if (matrixChanged == true) {
    // matrix display logic
    updateMatrix();
    matrixChanged = false;
  }
  generateFood();
} 
// theoretical example
void generateFood() {
  if(xPos == xFood &&yPos == yFood ){
    matrix[xFood][yFood] = 0;
       xFood = random(8);
       yFood = random(8);
       matrix[xFood][yFood] = 1;
       score ++;
  }
  matrixChanged = true;
}

void updateByteMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    lc.setRow(0, row, matrixByte[row]);
  }
}
void updateMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, matrix[row][col]);
    }
  }
}

void updatePositions() {
  
  
  xLastPos = xPos;
  yLastPos = yPos;
  if (xValue < minThreshold && menuIndex == 0 ) {
    if (xPos < matrixSize - 1) {
      xPos++;
    } 
    else {
      xPos = 0;
    }
  }
  if (xValue > maxThreshold && menuIndex == 0 ) {
    if (xPos > 0) {
      xPos--;
    }
    else {
      xPos = matrixSize - 1;
    }
  }

  if (yValue > maxThreshold && menuIndex == 0 ) {
    if (yPos < matrixSize - 1) {
      yPos++;
    } 
    else {
      yPos = 0;
    }
  }

  if (yValue < minThreshold && menuIndex == 0 ) {
    if (yPos > 0) {
      yPos--;
    }
    else {
      yPos = matrixSize - 1;
    }
  }
  if ((xPos != xLastPos || yPos != yLastPos) && menuIndex == 0) {
    matrixChanged = true;
    matrix[xLastPos][yLastPos] = 0;
    matrix[xPos][yPos] = 1;
  }  
}

