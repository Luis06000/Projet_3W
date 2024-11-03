#include "GPS.h"
#include "Config.h"

GPSSensor::GPSSensor(uint8_t rxPin, uint8_t txPin) 
    : gpsSerial(rxPin, txPin), latitude(0.0), longitude(0.0), 
      validData(false), invalidLocationCount(0) {}

bool GPSSensor::begin() {
    gpsSerial.begin(9600);
    
    // Attend un peu pour la stabilisation
    delay(100);
    
    // Vérifie si on reçoit des données NMEA
    unsigned long startTime = millis();
    while (millis() - startTime < 1000) {
        if (gpsSerial.available()) {
            char c = gpsSerial.read();
            if (c == '$') {  // Début d'une trame NMEA
                return true;
            }
        }
    }
    return false;
}

void GPSSensor::readData() {
    validData = false;
    
    unsigned long startTime = millis();
    while (millis() - startTime < params.TIMEOUT) {
        while (gpsSerial.available()) {
            if (gps.encode(gpsSerial.read())) {
                if (gps.location.isValid()) {
                    latitude = gps.location.lat();
                    longitude = gps.location.lng();
                    validData = true;
                    invalidLocationCount = 0;
                    return;
                }
            }
            delay(10);
        }
        delay(10);
    }
    
    if (!validData) {
        invalidLocationCount++;
    }
}

float GPSSensor::Latitude() {
    return validData ? latitude : 0.0;
}

float GPSSensor::Longitude() {
    return validData ? longitude : 0.0;
}

bool GPSSensor::hasValidData() {
    return validData;
}

uint8_t GPSSensor::InvalidLocationCount() {
    return invalidLocationCount;
}
