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
    void adjustClock(uint8_t newHour, uint8_t newMinute, uint8_t newSecond);
    void adjustDate(uint8_t newMonth, uint8_t newDay, int newYear);
    void resetRTC();

    RTC_DS1307 rtc;  // Instance de RTC_DS1307

private:
    char buffer[20];
    DateTime defaultTime;
};

extern RTC rtcSensor;
extern RTC_DS1307 rtc;

#endif
