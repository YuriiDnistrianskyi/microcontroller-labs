#include <ESP8266WiFi.h>
#include <espnow.h>

#include "../include/initESPNOW.h"

#include "../include/config.h"

const uint8_t** macAddress[] = {0x24, 0xD7, 0xEB, 0xEF, 0x59, 0xE3}; // 24:D7:EB:EF:59:E3

void handleSend(uint8_t *mac_addr, uint8_t sendStatus)
{
    if (sendStatus == 0)
    {
        Serial.println("Send success");
    }
    else
    {
        Serial.print("Send don`t success");
    }
}

void initESPNOW() 
{
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != 0) 
    {
        Serial.println("ESP_NOW don`t init");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(handleSend);

    esp_now_add_peer(macAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
