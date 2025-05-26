#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
    private:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        bool isFinished;

    public:
        Timer();
        String getTime();
        bool getFinished();
        void setHours(uint8_t h);
        void setMinutes(uint8_t m);
        void setFinished(bool f);
        void reset();
        void goTimer();
};

#endif // TIMER_H