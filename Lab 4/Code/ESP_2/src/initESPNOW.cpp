#include <ESP8266WiFi.h>
#include <espnow.h>

#include "../include/initESPNOW.h"

extern void sendButtonState();
extern bool buttonState;
extern bool flagLightLed;
extern bool flagStopLed;

void handleReceive(uint8_t *macAddress, uint8_t *data, uint8_t len)
{
    memcpy(&buttonState, data, sizeof(buttonState));
    buttonState ? flagLightLed = true : flagStopLed = true;
    sendButtonState();
}

void initESPNOW() 
{
    // Serial.print("MAC address: "); // 24:D7:EB:EF:59:E3
    // Serial.println(WiFi.macAddress());

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != 0)
    {
        Serial.println("ESP_NOW don`t init");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
    esp_now_register_recv_cb(handleReceive);
}
