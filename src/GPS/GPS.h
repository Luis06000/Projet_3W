#ifndef GPS_H
#define GPS_H

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

class GPSSensor {
public:
    GPSSensor(uint8_t rxPin = 3, uint8_t txPin = 4);
    void begin();
    void readData();
    float Longitude();
    float Latitude();
    uint8_t InvalidLocationCount();
    bool hasValidData();

private:
    SoftwareSerial gpsSerial;
    TinyGPSPlus gps;
    float latitude;
    float longitude;
    bool validData;
    uint8_t invalidLocationCount;
};

#endif // GPS_H