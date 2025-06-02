#include <FastLED.h>

#include "../include/config.h"
#include "../include/lightingLED.h"

void lightingLed(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue)
{
    FastLED.clear();
    for (int i = 0; i < numberOfLeds; i++)
    {
        leds[i] = CRGB(valueRed, valueGreen, valueBlue);
    }
    FastLED.show();
}