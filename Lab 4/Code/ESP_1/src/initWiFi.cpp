#include <ESP8266WiFi.h>

#include "../include/initWiFi.h"

#include "../include/config.h"

void initWiFi() {
    Serial.print("MAC address: ");
    Serial.println(WiFi.macAddress());
}
