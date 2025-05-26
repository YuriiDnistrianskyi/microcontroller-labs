#include <LiquidCrystal_I2C.h>

#include "../include/updateDisplay.h"

extern void sendTime();
extern Timer timer;
extern LiquidCrystal_I2C lcd;

void updateDisplay()
{
    // uint8_t hours = timer.getHours();
    // uint8_t minutes = timer.getMinutes();
    // uint8_t seconds = timer.getSeconds();

    String timerTime = timer.getTime();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(timerTime);

    sendTime();
}