#include <Adafruit_NeoPixel.h>

#include "../include/funcLeds.h"

#include "../include/config.h"
#include "../include/color.h"

extern Adafruit_NeoPixel strip;

void lightingLeds(Color colorLeds)
{
    strip.clear();
    for (int i = 0; i < numberOfLeds; i++)
    {
        strip.setPixelColor(i, strip.Color(colorLeds.red, colorLeds.green, colorLeds.blue));
    }
    strip.show();
}

void stopLeds()
{
    strip.clear();
    strip.show();
}
