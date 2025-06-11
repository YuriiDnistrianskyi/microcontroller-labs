#include <Arduino.h>
#include <espnow.h>

#include "../include/config.h"
#include "../include/initPins.h"
#include "../include/initESPNOW.h"

bool buttonState = false;
bool sendButtonState = false;

void setup() {
  Serial.begin(115200);
  initPins();
  initESPNOW();
}

void loop() {
  if (buttonState == true) {
    sendButtonState = !sendButtonState;
    esp_now_send(macAddress, (uint8_t *)sendButtonState, sizeof(sendButtonState));
    buttonState = false;
  }
}
