#include <ESP8266WiFi.h>

#include "../include/initWiFi.h"

#include "../include/config.h"

void initWiFi() {
    Serial.print("MAC address: "); // 24:D7:EB:EF:59:E3
    Serial.println(WiFi.macAddress());
}
