#ifndef GPS_H
#define GPS_H

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

extern float longitude;
extern float latitude;

void setupGPS();
void readGPSData();
float Longitude();
float Latitude();

#endif // GPS_H
