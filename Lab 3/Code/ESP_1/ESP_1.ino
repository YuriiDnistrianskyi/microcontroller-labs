#include <Arduino.h>

#include "include/initPins.h"
#include "include/espServer.h"

#include "include/Timer.h"
#include "include/ProgramState.h"

#include "include/timerFunc.h"
#include "include/updateDisplay.h"

Timer timer;
ProgramState programState = wait;
uint8_t updateDusplayAfterFinish = 0;

void setup() 
{
  Serial.begin(115200);
  initWiFi();
  initPins();
}

void loop()
{
  switch(programState) 
  {
    case wait:
      if (updateDusplayAfterFinish == 1) 
      {
        updateDisplay();
        updateDusplayAfterFinish = 0;
      }
      break;
    case go:
      goTime(); break;
    case hour:
      setHours(); break;
    case minute:
      setMinutes(); break;
  }
}
