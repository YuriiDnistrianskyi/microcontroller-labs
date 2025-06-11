#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "../include/initWiFi.h"

#include "../include/config.h"
#include "../include/html.h"

extern bool buttonState;
extern bool flagLightLed;
extern bool flagStopLed;

ESP8266WebServer server(80);

void handleRoot()
{
    server.send(200, "text/html", html);
}

void sendButtonState()
{
    server.send(200, "text/plain", String(buttonState));
}

void handleButtonClick()
{
    buttonState = !buttonState;
    buttonState ? flagLightLed = true : flagStopLed = true;
    sendButtonState();
}

void initWiFi()
{
    WiFi.begin(ssid, password);
    Serial.print("Connection...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(2000);
    }
    Serial.println("Connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, handleRoot);
    server.on("/click", HTTP_POST, handleButtonClick);
    server.on("/get_state", HTTP_GET, sendButtonState);

    server.begin();
}
