#include "GPS.h"

// Initialisation des variables globales
SoftwareSerial gpsSerial(3, 4); // RX = D3, TX = D4
TinyGPSPlus gps;

void setupGPS() {
    Serial.begin(9600);     // Pour afficher les résultats sur le moniteur série
    gpsSerial.begin(9600);  // Initialiser le port série logiciel pour le GPS
    Serial.println("Lecture des données GPS...");
}

void displayInfo() {
    Serial.print(F("Location: ")); 
    if (gps.location.isValid()) {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
    } else {
        Serial.print(F("INVALID"));
    }
    Serial.println();
}

void readGPSData() {
    // Lire les données du GPS via le port série logiciel
    while (gpsSerial.available() > 0) {
        char c = gpsSerial.read();
        if (gps.encode(c)) { // Si une phrase NMEA complète est décodée
            displayInfo();   // Affiche les informations GPS
        }
    }
}
