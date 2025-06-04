#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

inline const uint8_t ledPin = D6;
inline const uint8_t buttonPin = D5;

inline const uint8_t SDApin = D2;
inline const uint8_t SCLpin = D1;

inline const uint8_t numberOfLeds = 30; // 60 - 12

inline const uint32_t DEBOUNCE_TIME = 50; // ms

inline const uint8_t EEPROM_SIZE = 16;

inline const char* ssid = "Wi-Fi";
inline const char* password = "*********";

#endif //CONFIG_H  
