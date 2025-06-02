#include <LiquidCrystal_I2C.h>

#include "../include/updateDisplay.h"

extern void sendTime();
extern Timer timer;
extern LiquidCrystal_I2C lcd;

void updateDisplay()
{
    String timerTime = timer.getTime();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(timerTime);

    sendTime();
}