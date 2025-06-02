#ifndef INITPINS_H
#define INITPINS_H

#include <Arduino.h>

extern void notifyClients();
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

void setButtonState();
void IRAM_ATTR handleButton();
void initPins();

#endif // INITPINS_H