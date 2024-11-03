#include "Config.h"
#include "BME280Sensor.h"

uint8_t invalidBMECount = 0;

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

float BME280Sensor::Temperature() {
    float temperature = bme.readTemperature();

    if (isnan(temperature)) invalidBMECount++;
    else {
        invalidBMECount = 0;
        if (temperature < params.MIN_TEMP_AIR || temperature > params.MAX_TEMP_AIR) {
            ERREUR = 1;
        }
    }
    return temperature;
}

float BME280Sensor::Humidity() {
    float humidity = bme.readHumidity();

    if (isnan(humidity)) invalidBMECount++;
    else {
        invalidBMECount = 0;
        if (humidity < params.HYGR_MIN || humidity > params.HYGR_MAX) {
            ERREUR = 1;
        }
    }
    return humidity;
}

float BME280Sensor::Pressure() {
    float pressure = bme.readPressure() * 0.01F;

    if (isnan(pressure)) invalidBMECount++;
    else {
        invalidBMECount = 0;
        if (pressure < params.PRESSURE_MIN || pressure > params.PRESSURE_MAX) {
            ERREUR = 1;
        }
    }
    return pressure;
}
