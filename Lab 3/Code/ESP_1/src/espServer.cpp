#include <WiFi.h>
#include <WebServer.h>

#include "../include/espServer.h"

#include "../include/config.h"
#include "../include/html.h"
#include "../include/ProgramState.h"
#include "../include/Timer.h"

extern void command();
extern Timer timer;
extern ProgramState programState;

WebServer server(80);

void handleRoot() {
    server.send(200, "text/html", html);
}

void handleCommand() {
    command();
}

void handleSetHours() {
    programState = hour;
}

void handleSetMinutes() {
    programState = minute;
}

void sendTime() {
    String time = timer.getTime();
    server.send(200, "text/plain", time);
}

void initWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting...");
        delay(2000);
    }
    Serial.println("Connected to WiFi " + String(ssid));
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/command", HTTP_POST, handleCommand);
    server.on("/set_hours", HTTP_POST, handleSetHours);
    server.on("/set_minutes", HTTP_POST, handleSetMinutes);
    server.on("/time", HTTP_GET, sendTime);
    server.begin();
}
