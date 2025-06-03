#include <Arduino.h>

#include "include/config.h"
#include "include/initPins.h"
#include "include/initWiFi.h"
#include "include/getData.h"
#include "include/funcLeds.h"
#include "include/funcDisplay.h"
#include "include/color.h"

bool buttonState = true;
Color colorLeds;

bool flagSetLeds = true;
bool flagStopLeds = false;
bool flagNotifyClients = false;

void setup()
{
    Serial.begin(115200);
    Serial.println("Go");
    initPins();
    initWiFi();
    getData();
}

void loop()
{
    if (flagNotifyClients == true)
    {
        notifyClients();
        flagNotifyClients = false;
    }
    
    if (buttonState == true)
    {
        if (flagSetLeds == true)
        {
            lightingLeds(colorLeds);
            updateDisplayColor(colorLeds);

            flagSetLeds = false;
        }
    }
    else
    {
        if (flagStopLeds == true)
        {
            stopLeds();
            updateDisplayOff();

            flagStopLeds = false;
        }
    }
}
