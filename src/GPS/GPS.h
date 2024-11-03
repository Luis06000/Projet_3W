#ifndef GPS_H
#define GPS_H

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

class GPSSensor {
public:
    GPSSensor();
    void setup();
    void readData();
    float Longitude();
    float Latitude();
    uint8_t InvalidLocationCount();

private:
    SoftwareSerial gpsSerial;
    TinyGPSPlus gps;
    float latitude;
    float longitude;
    uint8_t invalidLocationCount;
};

#endif // GPS_H