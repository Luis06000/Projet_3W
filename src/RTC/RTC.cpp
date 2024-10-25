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
