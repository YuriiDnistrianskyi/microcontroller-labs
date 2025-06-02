#include <EEPROM.h>

#include "../include/getData.h"

#include "../include/color.h"
#include "../include/config.h"

extern Color colorLEDs;

void getData() {
    EEPROM.begin(EEPROM_SIZE);
    EEPROM.get(0, colorLEds);

    if (colorLEDs.initFlag != 1234) {
        colorLEDs.initFlag = 1234;
        colorLEDs.red = 150;
        colorLEDs.green = 150;
        colorLEDs.blue = 150;

        EEPROM.put(0, colorLEDs);
        EEPROM.commit();
    }
    EEPROM.end();
}