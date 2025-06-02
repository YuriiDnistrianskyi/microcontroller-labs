#include <FastLED.h>

#include "../include/config.h"
#include "../include/color.h"
#include "../include/funcLeds.h"

extern CRGB leds[numberOfLeds];

void lightingLeds(Color colorLeds)
{
    FastLED.clear();
    FastLED.show();
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
