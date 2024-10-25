#ifndef GPS_H
#define GPS_H

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Déclaration du port série logiciel pour le GPS
extern SoftwareSerial gpsSerial;
extern TinyGPSPlus gps;

// Déclaration des fonctions
void setupGPS();
void displayInfo();
void readGPSData();

#endif // GPS_H
