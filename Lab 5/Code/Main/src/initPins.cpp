#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "../include/initPins.h"

#include "../include/config.h"
#include "../include/color.h"
#include "../include/funcDisplay.h"

extern void notifyClients();
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;
extern bool flagNotifyClients;

extern Color colorLeds;

Adafruit_NeoPixel strip(numberOfLeds, ledPin, NEO_GRB + NEO_KHZ800)Adafruit_NeoPixel strip(numberOfLeds, ledPin, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile uint32_t lastDebounceTime = 0;

void setButtonState()
{
    buttonState = !buttonState;
    buttonState ? flagSetLeds = true : flagStopLeds = true;
}

void IRAM_ATTR handleButton()
{
    uint32_t nowTime = millis();

    if((nowTime - lastDebounceTime) > DEBOUNCE_TIME)
    {
        lastDebounceTime = nowTime;
        setButtonState();
        flagNotifyClients = true;
    }
}

void initPins()
{
    strip.begin();
    strip.show();
    strip.setBrightness(50);

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, RISING);

    Wire.begin(SDApin, SCLpin);
    lcd.init();
    lcd.backlight();
}
