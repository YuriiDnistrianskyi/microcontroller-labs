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
    uint8_t data = sendButtonState;
    esp_now_send(macAddress, &data, sizeof(sendButtonState));
    buttonState = false;
  }
}
