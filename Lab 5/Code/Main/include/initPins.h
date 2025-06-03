#ifndef INITPINS_H
#define INITPINS_H

#include <Arduino.h>

void setButtonState();
void IRAM_ATTR handleButton();
void initPins();

#endif // INITPINS_H