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

void RTC::printCurrentTime() {
    // Récupérer l'heure actuelle
    DateTime now = rtc.now();

    // Afficher l'heure au format JJ/MM/AAAA HH:MM:SS
    char buffer[33];
    snprintf(buffer, sizeof(buffer), "\nDate: %02d/%02d/%04d Heure: %02d:%02d:%02d", 
             now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());
    Serial.println(buffer);
}

void RTC::adjustClock(int newHour, int newMinute, int newSecond) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), newHour, newMinute, newSecond));
}

void RTC::adjustDate(int newYear, int newMonth, int newDay) {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(newYear, newMonth, newDay, now.hour(), now.minute(), now.second()));
}