#include <EEPROM.h>

#include "../include/getData.h"

#include "../include/color.h"
#include "../include/config.h"

extern Color colorLeds;

void getData() {
    EEPROM.begin(EEPROM_SIZE);
    EEPROM.get(0, colorLeds);

    if (colorLeds.initFlag != 1234) {
        colorLeds.initFlag = 1234;
        colorLeds.red = 150;
        colorLeds.green = 150;
        colorLeds.blue = 150;

        EEPROM.put(0, colorLeds);
        EEPROM.commit();
    }
}
