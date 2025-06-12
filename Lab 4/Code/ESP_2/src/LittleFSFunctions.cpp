#include <LittleFS.h>

#include "../include/LittleFSFunctions.h"

extern bool buttonState;

void initLittleFS()
{
    if (!LittleFS.begin())
    {
        Serial.println("LittleFS is not initialized");
        return;
    }
}

void updateDB()
{
    File dbRead = LittleFS.open("/database.csv", "r");
    if (!dbRead)
    {
        Serial.println("Failed to open database.csv (r)");
        return;
    }

    size_t sizeDB = dbRead.size();
    dbRead.close();

    File dbUpdate;
    if (sizeDB > 5000)
    {
        dbUpdate = LittleFS.open("/database.csv", "w");
    }
    else 
    {
        dbUpdate = LittleFS.open("/database.csv", "a");
    }

    if (!dbUpdate)
    {
        Serial.println("Failed to open database.csv (w or a)");
        return;
    }

    String data = "Time: " + String(millis() / 1000) + " Led State: " + (buttonState ? "ON" : "OFF");
    dbUpdate.println(data);
    dbUpdate.close();
}
