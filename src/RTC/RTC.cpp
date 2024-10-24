#include "RTC.h"
#include <Wire.h>
#include <SPI.h>
#include "Config.h"

RTC::RTC() {}

// Variable pour suivre le temps écoulé
unsigned long lastPrintTime = 0;

bool RTC::begin() {
    return rtc.begin();
}

bool RTC::isRunning() {
    return rtc.isrunning();
}

void RTC::adjustTimeFromSerial() {
    Serial.println("\nEntrez le jour (JJ), le mois (MM), l'année (AA), l'heure (HH) et les minutes (MM) au format: JJ MM AA HH MM");
    // Attendre la saisie de l'heure et des minutes
    while (Serial.available() < 14) {
    }

    int day = Serial.parseInt();
    int month = Serial.parseInt();
    int year = Serial.parseInt();
    int hour = Serial.parseInt();
    int minute = Serial.parseInt();

    rtc.adjust(DateTime(year, month, day, hour, minute, 0));
}

void RTC::printCurrentTime() {
    // Vérifier si le délai s'est écoulé depuis le dernier affichage
    if (millis() - lastPrintTime >= LOG_INTERVAL) {
        // Met à jour le temps du dernier affichage
        lastPrintTime = millis();

        // Récupérer l'heure actuelle
        DateTime now = rtc.now();

        // Afficher l'heure au format JJ/MM/AAAA HH:MM:SS
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
}
