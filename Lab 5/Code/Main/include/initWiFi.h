#ifndef INITWIFI_H
#define INITWIFI_H

#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

void notifyClients();
void handleWebSocket(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len);
void initWiFi();

#endif // INITWIFI_H