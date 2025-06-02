// #include <FastLED.h>
#include <Adafruit_NeoPixel.h>

#include "../include/config.h"
#include "../include/color.h"
#include "../include/funcLeds.h"

// extern CRGB leds[numberOfLeds];
extern Adafruit_NeoPixel strip;

void lightingLeds(Color colorLeds)
{
    // FastLED.clear();
    // FastLED.show();
    strip.clear();
    for (int i = 0; i < numberOfLeds; i++)
    {
        // leds[i] = CRGB(colorLeds.red, colorLeds.green, colorLeds.blue);
        strip.setPixelColor(i, strip.Color(colorLeds.red, colorLeds.green, colorLeds.blue));
    }
    // FastLED.show();
    strip.show();
}

void stopLeds()
{
    // FastLED.clear();
    // FastLED.show();
    strip.clear();
    strip.show();
}
