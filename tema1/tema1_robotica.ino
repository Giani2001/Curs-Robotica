const int potRedPin = A0;
const int potGreenPin = A1;
const int potBluePin = A2;
const int redLedPin = 9;
const int greenLedPin = 10;
const int blueLedPin = 11;
const int maxValuePot = 1023;
const int minValuePot = 0;
const int maxValueLed = 255;
const int minValueLed = 0;
int potRedValue = 0;
int potGreenValue = 0;
int potBlueValue = 0;
void setup() {
// initialize serial communication at 9600 bits per second:
  initializePotPin(potRedPin, potBluePin, potGreenPin);
  initializePin(redLedPin, blueLedPin, greenLedPin);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  readPotValues(potRedValue, potBlueValue, potGreenValue);
  setAllPotValues(potRedValue, potBlueValue, potGreenValue);
  setLed(potRedValue, potGreenValue, potBlueValue);
   
}

int setPotValue(int potValue){
  return map(potValue, minValuePot, maxValuePot, minValueLed, maxValueLed);
}

int setAllPotValues(int &potRedValue, int &potBlueValue, int &potGreenValue){
  potRedValue = setPotValue(potRedValue);
  potGreenValue = setPotValue(potGreenValue);
  potBlueValue = setPotValue(potBlueValue);
}

void setLed(int potRedValue, int potGreenValue, int potBlueValue){
  analogWrite(redLedPin, potRedValue);
  analogWrite(greenLedPin, potGreenValue);
  analogWrite(blueLedPin, potBlueValue);

}

void initializePotPin(const int potRedPin, const int potBluePin, const int potGreenPin){
  pinMode(potRedPin, INPUT);
  pinMode(potGreenPin, INPUT);
  pinMode(potBluePin, INPUT);
}

void initializePin(const int redLedPin, const int blueLedPin, const int greenLedPin){
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void readPotValues(int &potRedValue, int &potBlueValue, int &potGreenValue){
  potRedValue = analogRead(potRedPin);
  potGreenValue = analogRead(potGreenPin);
  potBlueValue = analogRead(potBluePin);
}