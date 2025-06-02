#include <Arduino.h>

#include "include/config.h"
#include "include/initPins.h"
#include "include/initWiFi.h"
#include "include/getData.h"
#include "include/lightingLED.h"
#include "include/updateDisplay.h"
#include "include/color.h"

bool buttonState = true;
Color colorLEds;

uint8_t valueRed = 150;
uint8_t valueGreen = 150;
uint8_t valueBlue = 150;


bool flagSetLeds = true;
bool flagStopLeds = false;

void setup()
{
    Serial.begin(115200);
    initPins();
    initWiFi();
    getData();
}

void loop()
{
    if (buttonState == true)
    {
        if (flagSetLeds == true)
        {
            lightingLed(valueRed, valueGreen, valueBlue);
            updateDisplay(valueRed, valueGreen, valueBlue);

            flagSetLeds = false;
        }
    }
    else
    {
        if (flagStopLeds == true)
        {
            lightingLed(0, 0, 0);
            updateDisplay(0, 0, 0);
            flagStopLeds = false;
        }
    }
}
