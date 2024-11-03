#include "GPS.h"
#include "Config.h"

// Constructeur
GPSSensor::GPSSensor() : gpsSerial(2, 3), latitude(0.0), longitude(0.0), invalidLocationCount(0) {}

void GPSSensor::setup() {
    gpsSerial.begin(9600);
}

void GPSSensor::readData() {
    unsigned long startTime = millis();

    while (millis() - startTime < params.TIMEOUT * 1000) {
        while (gpsSerial.available() > 0) {
            if (gps.encode(gpsSerial.read())) {
                if (gps.location.isValid()) longitude = gps.location.lng(), latitude = gps.location.lat(), invalidLocationCount = 0;
                else invalidLocationCount++;
            }
        }
    }
}

float GPSSensor::Latitude() {
    return latitude;
}

float GPSSensor::Longitude() {
    return longitude;
}

uint8_t GPSSensor::InvalidLocationCount() {
    return invalidLocationCount;
}
