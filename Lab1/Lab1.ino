#include "pins.H"

bool stateButton = LOW;
bool stateLed = LOW;

long prevDebounceTime = 0;
long debounceTime = 200;

long prevLedTime = 0;
long interval = 2000;
uint8_t indexArray = 0;

long intervalArray[] = {2000, 1000, 500, 200};


void handleOnClick() {
  long currentTime = millis();

  if ((currentTime - prevDebounceTime) > debounceTime) {
    indexArray++;
    if (indexArray == 4) {
      indexArray = 0;
    }
    prevDebounceTime = currentTime;
  }
}


void ledPins(long delayTime) {
  long startTime = millis();

  if ((startTime - prevLedTime) >= delayTime) {
    prevLedTime = startTime;
    stateLed = !stateLed;
  }

  digitalWrite(ledPin1, stateLed);
  digitalWrite(ledPin2, stateLed);
  digitalWrite(ledPin3, stateLed);
}


void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleOnClick, FALLING);
}

void loop() {
  interval = intervalArray[indexArray];
  ledPins(interval);
}
