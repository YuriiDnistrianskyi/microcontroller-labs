#include "../include/Timer.h"

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->isFinished = false;
}

String Timer::getTime()
{
    String time = String(this->hours) + ":" + String(this->minutes) + ":" + String(this->seconds);
    return time;
}

bool Timer::getFinished()
{
    return this->isFinished;
}

void Timer::setHours(uint8_t h) 
{
    this->hours = h;
    this->isFinished = false;
}

void Timer::setMinutes(uint8_t m) 
{
    this->minutes = m;
    this->isFinished = false;
}

void Timer::setFinished(bool f) 
{
    this->isFinished = f;
}

void Timer::reset()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

void Timer::goTimer() {
    if (this->seconds > 0)
    {
        this->seconds--;
    }
    else if (this->seconds <= 0 && this->minutes > 0) 
    {
        this->seconds = 59;
        this->minutes--;
        if (this->minutes <= 0 && this->hours > 0) 
        {
            this->minutes = 59;
            this->hours--;
        } 
    }
    else if (this->hours > 0)
    {
        this->seconds = 59;
        this->minutes = 59;
        this->hours--;
    }
    else 
    {
        this->isFinished = true;
    }
}