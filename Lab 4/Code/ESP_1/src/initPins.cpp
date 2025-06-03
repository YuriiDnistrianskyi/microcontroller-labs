#include "../include/initPins.h"

#include "../include/config.h"

extern bool buttonState;
volatile uint32_t lastDebounceTime = 0;

void handleButtonClick() {
    uint32_t currentTime = millis();

    if ((currentTime - lastDebounceTime) > DEBOUNCE_TIME) {
        lastDebounceTime = currentTime;
        buttonState = true;
    }
}

void initPins() {
    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonClick, RISING);
}
