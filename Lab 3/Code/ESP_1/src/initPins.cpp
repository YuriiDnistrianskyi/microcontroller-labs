#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "../include/initPins.h"

#include "../include/config.h"
#include "../include/Timer.h"
#include "../include/ProgramState.h"
#include "../include/updateDisplay.h"

#define DEBOUNCE_TIME 50

extern Timer timer;
extern ProgramState programState;
extern uint8_t updateDusplayAfterFinish;

LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile uint32_t lastDebounceTime1 = 0;
volatile uint32_t lastDebounceTime2 = 0;
volatile uint32_t lastDebounceTime3 = 0;

void command() {
    if (programState == go) 
    {
        timer.reset();
    }
    else if (programState == finish) 
    {
        programState = wait;
        timer.setFinished(false);
        updateDusplayAfterFinish = 1;
    }
    else
    {
        programState = go;
    }
}

void IRAM_ATTR button1Handler() 
{
    uint32_t currentTime = millis();

    if ((currentTime - lastDebounceTime1) > DEBOUNCE_TIME)
    {
        lastDebounceTime1 = currentTime;
        command();
    }
}

void IRAM_ATTR button2Handler() 
{
    uint32_t currentTime = millis();

    if ((currentTime - lastDebounceTime2) > DEBOUNCE_TIME)
    {
        lastDebounceTime2 = currentTime;
        programState = hour;
    }
}

void IRAM_ATTR button3Handler() 
{
    uint32_t currentTime = millis();

    if ((currentTime - lastDebounceTime3) > DEBOUNCE_TIME)
    {
        lastDebounceTime3 = currentTime;
        programState = minute;
    }
}

void initPins()
{
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);

    attachInterrupt(digitalPinToInterrupt(button1), button1Handler, RISING);
    attachInterrupt(digitalPinToInterrupt(button2), button2Handler, RISING);
    attachInterrupt(digitalPinToInterrupt(button3), button3Handler, RISING);

    Wire.begin(21, 22);
    lcd.init();
    lcd.backlight();
    updateDisplay();
}