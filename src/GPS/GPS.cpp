#include "GPS.h"

// Initialisation des variables globales
SoftwareSerial gpsSerial(2, 3);
TinyGPSPlus gps;

float latitude = 0.0;
float longitude = 0.0;

void setupGPS() {
    gpsSerial.begin(9600);  // Initialiser le port série logiciel pour le GPS
}

void readGPSData() {
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) { // Si une phrase NMEA complète est décodée
            if (gps.location.isValid()) {
                longitude = gps.location.lng();  // Assigner la valeur correctement
                latitude = gps.location.lat();   // Assigner la valeur correctement
            }
        }
    }
}

float Latitude() {
    return latitude;
}

float Longitude() {
    return longitude;
}
