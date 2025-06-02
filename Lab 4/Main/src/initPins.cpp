#include <FastLED.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "../include/config.h"
#include "../include/initPins.h"
#include "../include/updateDisplay.h"

extern void notifyClients();
extern bool buttonState;
extern bool flagSetLeds;
extern bool flagStopLeds;

extern uint8_t valueRed;
extern uint8_t valueGreen;
extern uint8_t valueBlue;

LiquidCrystal_I2C lcd(0x27, 16, 2);

CRGB leds[numberOfLeds];
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
        Serial.println("Button");
        lastDebounceTime = nowTime;
        setButtonState();
        notifyClients();
    }
}

void initPins()
{
    FastLED.addLeds<WS2812B, ledPin, GRB>(leds, numberOfLeds);
    FastLED.clear();
    FastLED.show();

    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, RISING);

    Wire.begin(SDApin, SCLpin);
    lcd.init();
    lcd.backlight();
    updateDisplay(valueRed, valueGreen, valueBlue);
}