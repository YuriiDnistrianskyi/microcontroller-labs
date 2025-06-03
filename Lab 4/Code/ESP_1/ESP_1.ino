#include <Arduino.h>

#include "include/initPins.h"
#include "include/initWiFi.h"

bool buttonState = false;

void setup() {
  Serial.begin(115200);
  initPins();
  initWiFi();
}

void loop() {
  if (buttonState == true) {


    buttonState = false;
  }
}
