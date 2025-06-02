#include <LiquidCrystal_I2C.h>

#include "../include/funcDisplay.h"

#include "../include/config.h"
#include "../include/color.h"

extern LiquidCrystal_I2C lcd;

void updateDisplayColor(Color colorLeds) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("R: ");
    lcd.print(colorLeds.red);

    lcd.setCursor(8, 0);
    lcd.print("G: ");
    lcd.print(colorLeds.green);

    lcd.setCursor(0, 1);
    lcd.print("B: ");
    lcd.print(colorLeds.blue);
}

void updateDisplayOff() {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("OFF");
}
