#include "RTC.h"

RTC::RTC() {}

bool RTC::begin() {
    Wire.begin();
    return rtc.begin() && rtc.isrunning();
}

bool RTC::isRunning() {
    return rtc.isrunning();
}

void RTC::setDefaultTime() {
    defaultTime = rtc.now().unixtime();
}

const char* RTC::currentTime() {
    DateTime now = rtc.now();
    
    snprintf_P(buffer, sizeof(buffer), PSTR("%02d/%02d/%04d %02d:%02d:%02d"), 
        now.day(), now.month(), now.year(), 
        now.hour(), now.minute(), now.second());
    return buffer;
}

void RTC::adjustTime(uint8_t hour, uint8_t min, uint8_t sec) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), hour, min, sec));
}

void RTC::adjustDate(uint8_t month, uint8_t day, uint16_t year) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(year, month, day, now.hour(), now.minute(), now.second()));
}

void RTC::resetRTC() {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

DateTime RTC::now() {
    return rtc.now();
}