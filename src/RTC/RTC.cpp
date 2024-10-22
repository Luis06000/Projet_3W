#include "RTC.h"
#include <Wire.h>
#include <SPI.h>

RTC::RTC() {}

bool RTC::begin() {
    return rtc.begin();
}

bool RTC::isRunning() {
    return rtc.isrunning();
}

void RTC::adjustTime() {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void RTC::printCurrentTime() {
    DateTime now = rtc.now();

    Serial.print("Date: ");
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" Heure: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);
}