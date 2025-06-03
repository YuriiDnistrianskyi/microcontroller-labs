#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

inline uint8_t buttonPin = D1;
inline uint32_t DEBOUNCE_TIME = 50; 

inline uint8_t macAddress[] = {0x24, 0xD7, 0xEB, 0xEF, 0x59, 0xE3}; // 24:D7:EB:EF:59:E3

#endif // CONFIG_H
