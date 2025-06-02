#ifndef INITWIFI_H
#define INITWIFI_H

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

extern void setButtonState();
extern uint8_t valueRed;
extern uint8_t valueGreen;
extern uint8_t valueBlue;
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

void notifyClients();
void handleWebSocket(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len);
void initWiFi();

#endif // INITWIFI_H