#ifndef FUNC_LEDS_H
#define FUNC_LEDS_H

#include <Arduino.h>

#include "config.h"
#include "color.h"

// void lightingLed(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue);
void lightingLeds(Color colorLeds);

void stopLeds();

#endif // FUBC_LEDS_H