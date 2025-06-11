#include <Arduino.h>
#include <ESP8266WebServer.h>

#include "../include/config.h"
#include "../include/initPins.h"
#include "../include/initESPNOW.h"
#include "../include/initWiFi.h"

extern ESP8266WebServer server;

bool buttonState = false;
bool flagLightLed = false;
bool flagStopLed = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Go");
  initPins();
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
