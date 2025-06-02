#include <FastLED.h>

#include "../include/config.h"
#include "../include/color.h"
#include "../include/funcLeds.h"

// void lightingLed(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue)
// {
//     FastLED.clear();
//     for (int i = 0; i < numberOfLeds; i++)
//     {
//         leds[i] = CRGB(valueRed, valueGreen, valueBlue);
//     }
//     FastLED.show();
// }

extern CRGB leds[numberOfLeds];

void lightingLeds(Color colorLeds)
{
    FastLED.clear();
    for (int i = 0; i < numberOfLeds; i++)
    {
        leds[i] = CRGB(colorLeds.red, colorLeds.green, colorLeds.blue);
    }
    FastLED.show();
}

void stopLeds()
{
    FastLED.clear();
    FastLED.show();
}
