#include "GPS.h"

// Initialisation des variables globales
SoftwareSerial gpsSerial(2, 3);
TinyGPSPlus gps;

void setupGPS() {
    gpsSerial.begin(9600);  // Initialiser le port série logiciel pour le GPS
}

void displayInfo() {
    Serial.print(F("Location: ")); 
    if (gps.location.isValid()) {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
    } else {
        Serial.print(F("NA"));
    }
    Serial.println();
}

void readGPSData() {
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) { // Si une phrase NMEA complète est décodée
            displayInfo();   // Affiche les informations GPS
        }
    }
}
