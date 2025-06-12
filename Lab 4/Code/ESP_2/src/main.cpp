#include <Arduino.h>
#include <ESP8266WebServer.h>

#include "../include/config.h"
#include "../include/initPins.h"
#include "../include/initESPNOW.h"
#include "../include/initWiFi.h"
#include "../include/LittleFSFunctions.h"

extern ESP8266WebServer server;

bool buttonState = false;
bool flagLightLed = false;
bool flagStopLed = false;

void setup() {
  Serial.begin(115200);
  initPins();
  initLittleFS();
  initESPNOW(); 
  initWiFi();
}

void loop() {
  server.handleClient();

  if (buttonState == true) 
  {
    if (flagLightLed == true) 
    {
      digitalWrite(ledPin, HIGH);
      updateDB();
      flagLightLed = false;
    }
  }
  else 
  {
    if (flagStopLed == true) 
    {
      digitalWrite(ledPin, LOW);
      updateDB();
      flagStopLed = false;
    }
  }
}
