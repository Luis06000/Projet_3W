#ifndef RTC_H
#define RTC_H

#include <RTClib.h>

class RTC {
public:
    RTC();
    bool begin();
    bool isRunning();
    void setDefaultTime();
    const char* currentTime();
    void adjustTime(uint8_t hour, uint8_t min, uint8_t sec);
    void adjustDate(uint8_t month, uint8_t day, uint16_t year);
    void resetRTC();
    DateTime now();

private:
    RTC_DS1307 rtc;
    char buffer[20];
    uint32_t defaultTime;
};

#endif
