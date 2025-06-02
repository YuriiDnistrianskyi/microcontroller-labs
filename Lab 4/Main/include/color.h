#ifndef COLOR_H
#define COLOR_H

#include <Arduino.h>

struct Color {
    uint8_t initFlag = 0;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#endif // COLOR_H