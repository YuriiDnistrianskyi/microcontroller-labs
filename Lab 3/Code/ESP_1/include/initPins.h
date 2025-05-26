#ifndef INITPINS_H
#define INITPINS_H

#include <Arduino.h>
#include "../include/Timer.h"
#include "../include/ProgramState.h"

extern Timer timer1;
extern Timer timer2;
extern uint8_t timerNumber;
extern ProgramState programState;

void IRAM_ATTR button1Handler();
void IRAM_ATTR button2Handler();
void IRAM_ATTR button3Handler();
void IRAM_ATTR button4Handler();
void initPins();

#endif // INITPINS_H