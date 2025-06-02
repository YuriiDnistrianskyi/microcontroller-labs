#include <LiquidCrystal_I2C.h>

#include "../include/updateDisplay.h"

#include "../include/config.h"

extern LiquidCrystal_I2C lcd;

void updateDisplay(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("R: ");
    lcd.print(valueRed);

    lcd.setCursor(8, 0);
    lcd.print("G: ");
    lcd.print(valueGreen);

    lcd.setCursor(0, 1);
    lcd.print("B: ");
    lcd.print(valueBlue);
}
