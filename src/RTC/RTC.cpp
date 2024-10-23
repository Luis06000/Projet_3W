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
    Serial.println("\n Entrez le jour (JJ), le mois (MM), l'année (AAAA), l'heure (HH) et les minutes (MM) au format: JJ MM AAAA HH MM");
    // Attendre la saisie de l'heure et des minutes
    while (Serial.available() < 16) {
        delay(10);
    }

    int day = Serial.parseInt();
    int month = Serial.parseInt();
    int year = Serial.parseInt();
    int hour = Serial.parseInt();
    int minute = Serial.parseInt();

    rtc.adjust(DateTime(year, month, day, hour, minute, 0));
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