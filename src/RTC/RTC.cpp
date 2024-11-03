#include "RTC.h"
#include <Wire.h>
#include <SPI.h>

RTC::RTC() {}

bool RTC::begin() {
    if (!rtc.begin()) {
        return false;
    }

    if (!rtc.isrunning()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Initialiser avec la date et l'heure de compilation
    }
    return true;
}

bool RTC::isRunning() {
    return rtc.isrunning();
}

void RTC::setDefaultTime() {
    defaultTime = rtc.now();
}

const char* RTC::currentTime() {
    DateTime now = rtc.now();

    snprintf(buffer, sizeof(buffer), "\n%02d/%02d/%04d %02d:%02d:%02d", 
             now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());

    return buffer;
}

void RTC::adjustClock(uint8_t newHour, uint8_t newMinute, uint8_t newSecond) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), newHour, newMinute, newSecond));
}

void RTC::adjustDate(uint8_t newMonth, uint8_t newDay, int newYear) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(newYear, newMonth, newDay, now.hour(), now.minute(), now.second()));
}

void RTC::resetRTC() {
    rtc.adjust(defaultTime);
}