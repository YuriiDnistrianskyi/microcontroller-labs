#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <EEPROM.h>

#include "../include/initWiFi.h"

#include "../include/config.h"
#include "../include/color.h"
#include "../include/html.h"

extern Color colorLeds;
extern bool flagSetLeds;
extern void setButtonState();
extern bool buttonState;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void notifyClients()
{
    StaticJsonDocument<200> doc;
    doc["red"] = colorLeds.red;
    doc["green"] = colorLeds.green;
    doc["blue"] = colorLeds.blue;
    doc["button"] = buttonState;
    String json;
    serializeJson(doc, json);
    ws.textAll(json);
}

void handleWebSocket(AsyncWebSocket* ws, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len)
{
    if (type == WS_EVT_DATA)
    {
        data[len] = 0;
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, (const char*)data);

        if (!error)
        {
            if (doc["red"])
            {
                colorLeds.red = doc["red"];
                colorLeds.green = doc["green"];
                colorLeds.blue = doc["blue"];
                
                flagSetLeds = true;

                EEPROM.put(0, colorLeds);
                EEPROM.commit();
            }

            if (doc["setState"])
            {
                setButtonState();
            }

            notifyClients();
        }
    }
}

void initWiFi()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting...");
        delay(1000);
    }
    Serial.println("Connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.addHandler(&ws);
    ws.onEvent(handleWebSocket);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest* request)
    {
        request->send(200, "text/html", html);
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request){
        request->send(200, "text/plain", "Favicon");
    });    

    server.begin();
}
