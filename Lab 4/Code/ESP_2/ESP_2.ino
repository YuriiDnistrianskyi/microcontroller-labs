#include <Arduino.h>

#include "include/config.h"
#include "include/initPins.h"
#include "include/initESPNOW.h"

bool buttonState = false;
bool flagLightLed = false;
bool flagStopLed = false;

void setup() {
  Serial.begin(115200);
  initPins();
  initESPNOW(); 
}

void loop() {
  if (buttonState == true) 
  {
    if (flagLightLed == true) 
    {
      digitalWrite(ledPin, HIGH);
      flagLightLed = false;
    }
  }
  else 
  {
    if (flagStopLed == true) 
    {
      digitalWrite(ledPin, LOW);
      flagStopLed = false;
    }
  }
}
