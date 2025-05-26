#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "../include/timerFunc.h"

#include "../include/config.h"
#include "../include/Timer.h"
#include "../include/ProgramState.h"
#include "../include/updateDisplay.h"

extern Timer timer;
extern ProgramState programState;

extern LiquidCrystal_I2C lcd;

uint32_t lastTimeCheck;
uint8_t lastHourValue = 0;
uint8_t lastMinuteValue = 0;

void goTime()
{
    uint32_t currentTime = millis();

    if (currentTime - lastTimeCheck >= 1000)
    {
        lastTimeCheck = currentTime;
        
        timer.goTimer();
        updateDisplay();

        bool isFinishedTimer = timer.getFinished();

        if (isFinishedTimer == 1)
        {
            finishTimer();
        }
    }
}

void setHours() {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    if (value != lastHourValue) {
        lastHourValue = value;
        timer.setHours(value / 2.56); // 0 : 99
        updateDisplay();
    }
}

void setMinutes() {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    if (value != lastMinuteValue) {
        lastMinuteValue = value;
        timer.setMinutes(value / 4.25); // 0 : 59
        updateDisplay();
    }
}

void finishTimer() {
    programState = finish;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Timer finished!");
}
