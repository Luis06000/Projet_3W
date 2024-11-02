#include "Config.h"
#include "BME280Sensor.h"

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

float BME280Sensor::Temperature() {
    temperature = bme.readTemperature();
    
    // Vérifier les limites de température
    if (temperature < params.MIN_TEMP_AIR || temperature > params.MAX_TEMP_AIR) {
        ERREUR = 1;  // Définir ERREUR à 1 si la température est hors limites
    }
    return temperature;
}

float BME280Sensor::Humidity() {
    humidity = bme.readHumidity();
    
    // Vérifier les limites d'humidité
    if (humidity < params.HYGR_MIN || humidity > params.HYGR_MAX) {
        ERREUR = 1;  // Définir ERREUR à 1 si l'humidité est hors limites
    }
    return humidity;
}

float BME280Sensor::Pressure() {
    pressure = bme.readPressure() * 0.01F;
    
    // Vérifier les limites de pression
    if (pressure < params.PRESSURE_MIN || pressure > params.PRESSURE_MAX) {
        ERREUR = 1;  // Définir ERREUR à 1 si la pression est hors limites
    }
    return pressure;
}

