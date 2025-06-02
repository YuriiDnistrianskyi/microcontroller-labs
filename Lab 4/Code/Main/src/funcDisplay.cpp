#include <LiquidCrystal_I2C.h>

#include "../include/funcDisplay.h"

#include "../include/config.h"
#include "../include/color.h"

extern LiquidCrystal_I2C lcd;

// void updateDisplay(uint8_t valueRed, uint8_t valueGreen, uint8_t valueBlue) {
//     lcd.clear();

//     lcd.setCursor(0, 0);
//     lcd.print("R: ");
//     lcd.print(valueRed);

//     lcd.setCursor(8, 0);
//     lcd.print("G: ");
//     lcd.print(valueGreen);

//     lcd.setCursor(0, 1);
//     lcd.print("B: ");
//     lcd.print(valueBlue);
// }


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
