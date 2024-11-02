#include "RTC.h"
#include <Wire.h>
#include <SPI.h>

RTC::RTC() {}

bool RTC::begin() {
    if (!rtc.begin()) {
        return false;
    }

    // Vérifier si l'horloge est en cours de fonctionnement
    if (!rtc.isrunning()) {
        // Si elle n'est pas en marche, régler l'horloge sur la date et l'heure actuelles
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Initialiser avec la date et l'heure de compilation
    }
    return true;
}

bool RTC::isRunning() {
    return rtc.isrunning();
}

const char* RTC::currentTime() {
    DateTime now = rtc.now(); // Récupérer l'heure actuelle

    snprintf(buffer, sizeof(buffer), "\n%02d/%02d/%04d %02d:%02d:%02d", 
             now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());

    return buffer;
}

void RTC::adjustClock(int newHour, int newMinute, int newSecond) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), newHour, newMinute, newSecond));
}

void RTC::adjustDate(int newYear, int newMonth, int newDay) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(newYear, newMonth, newDay, now.hour(), now.minute(), now.second()));
}

void RTC::resetRTC() {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()));
}