/* 
 * BLINK_MATRIX_002.ino
 * A program that blinks a group of LEDs in a set pattern.
 * 
 * @auth ccpaz@fastech.com.ph
 * @init 03/31/19
 */

// Pin assignment
const int digitalPin2 = 2;
const int digitalPin3 = 3;
const int digitalPin4 = 4;
const int digitalPin5 = 5;
const int digitalPin6 = 6;
const int digitalPin7 = 7;
const int digitalPin8 = 8;
const int digitalPin9 = 9;
const int digitalPin10 = 10;
const int digitalPin11 = 11;
const int digitalPin12 = 12;
const int digitalPin13 = 13;


void setup() {
  int pinInit = 2;
  int pinCount = 14;
  for (int count = pinInit; count < pinCount; count++) {
    pinMode(count, OUTPUT);
  }                                           
  randomSeed(analogRead(0));
}

void loop() {
  initializationFunction();
  randomTriplePairFunction();
  randomDoublePairFunction();
  randomSinglePairFunction();
  exitFunction();
  // Uncomment below and comment above when board troubleshooting.
//  troubleshootFunction();
}

void initializationFunction() {
  int setDelay = 1000;
  int setLED = 2;
  int LEDLimit = 14;
  for (int LED = setLED; LED < LEDLimit; LED++) {
    digitalWrite(LED, HIGH);
    delay(setDelay);
  }
}

void randomTriplePairFunction() {
  int setCount = 0;
  int countLimit = 300;
  int pinInitMin = 2;
  int pinInitMax = 14;
  for (int count = setCount; count < countLimit; count++) {
    int randomLEDTrigger3 = random(pinInitMin, pinInitMax);
    int randomLEDTrigger2 = random(pinInitMin, pinInitMax);
    int randomLEDTrigger1 = random(pinInitMin, pinInitMax);
    if (randomLEDTrigger1 != randomLEDTrigger2 && randomLEDTrigger2 != randomLEDTrigger3) {
      triplePairAlgorithm(randomLEDTrigger1, randomLEDTrigger2, randomLEDTrigger3);
    }
    else {
      randomLEDTrigger1 = random(pinInitMin, pinInitMax);
      randomLEDTrigger2 = random(pinInitMin, pinInitMax);
    }
  }
}

void randomDoublePairFunction() {
  int setCount = 0;
  int countLimit = 300;
  int pinInitMin = 2;
  int pinInitMax = 14;
  for (int count = setCount; count < countLimit; count++) {
    int randomLEDTrigger2 = random(pinInitMin, pinInitMax);
    int randomLEDTrigger1 = random(pinInitMin, pinInitMax);
    if (randomLEDTrigger1 != randomLEDTrigger2) {
      doublePairAlgorithm(randomLEDTrigger1, randomLEDTrigger2);
    }
    else {
      randomLEDTrigger1 = random(pinInitMin, pinInitMax); 
    }
  }
}

void randomSinglePairFunction() {
  int setCount = 0;
  int countLimit = 300;
  int pinInitMin = 2;
  int pinInitMax = 14;
  int setDelay = 25;
  for (int count = setCount; count < countLimit; count++) {
    int randomLED = random(pinInitMin, pinInitMax);
    digitalWrite(randomLED,HIGH);
    delay(setDelay);
    digitalWrite(randomLED, LOW);
  }
}

void exitFunction() {
  int setDelay = 1000;
  int setLED = 13;
  int LEDLimit = 1;
  for (int LED = setLED; LED > LEDLimit; LED--) {
    digitalWrite(LED, HIGH);
  }
  delay(setDelay);
  for (int LED = setLED; LED > LEDLimit; LED--) {
    digitalWrite(LED, LOW);
    delay(setDelay);
  }
}

void triplePairAlgorithm(int LEDTrigger1, int LEDTrigger2, int LEDTrigger3) {
  int setDelay = 25;
  digitalWrite(LEDTrigger1, HIGH);
  digitalWrite(LEDTrigger2, HIGH);
  digitalWrite(LEDTrigger3, HIGH);
  delay(setDelay);
  digitalWrite(LEDTrigger1, LOW);
  digitalWrite(LEDTrigger2, LOW);
  digitalWrite(LEDTrigger2, LOW);
}

void doublePairAlgorithm(int LEDTrigger1, int LEDTrigger2) {
  int setDelay = 25;
  digitalWrite(LEDTrigger1, HIGH);
  digitalWrite(LEDTrigger2, HIGH);
  delay(setDelay);
  digitalWrite(LEDTrigger1, LOW);
  digitalWrite(LEDTrigger2, LOW);
}

void troubleshootFunction() {
  // Lights up all the LEDs in the circuit
  int ledInit = 2;
  int ledLimit = 14;
  for (int count = ledInit; count < ledLimit; count++) {
    digitalWrite(count, HIGH);
  }
}
