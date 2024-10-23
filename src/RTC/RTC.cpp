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

void RTC::adjustTimeFromSerial() {
    Serial.println("\n Entrez l'heure (HH) et les minutes (MM) au format: HH MM");
    // Attendre la saisie de l'heure et des minutes
    while (Serial.available() < 5) {
        delay(10);
    }

    int hour = Serial.parseInt();
    int minute = Serial.parseInt();

    // Obtenir la date actuelle depuis l'horloge RTC
    DateTime now = rtc.now();

    rtc.adjust(DateTime(now.year(), now.month(), now.day(), hour, minute, 0));
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

    Serial.println();
}