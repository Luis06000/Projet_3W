#include "BME280Sensor.h"

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

void BME280Sensor::readSensor() {
    // Vérifier si la lecture de la température est activée
    if (TEMP_AIR) {
        temperature = bme.readTemperature();
        Serial.print(F("Température : "));
        Serial.print(temperature, 1);
        Serial.println(F(" °C"));
        
        // Vérifier les limites de température
        if (temperature < MIN_TEMP_AIR || temperature > MAX_TEMP_AIR) {
            ERREUR = 1;  // Définir ERREUR à 1 si la température est hors limites
        }
    }

    // Vérifier si la lecture de l'humidité est activée
    if (HYGR) {
        humidity = bme.readHumidity();
        Serial.print(F("Humidité : "));
        Serial.print(humidity, 1);
        Serial.println(F(" %"));
        
        // Vérifier les limites d'humidité
        if (humidity < HYGR_MIN || humidity > HYGR_MAX) {
            ERREUR = 1;  // Définir ERREUR à 1 si l'humidité est hors limites
        }
    }

    // Vérifier si la lecture de la pression est activée
    if (PRESSURE) {
        pressure = bme.readPressure() * 0.01F;  // Convertir en hPa
        Serial.print(F("Pression : "));
        Serial.print(pressure, 1);
        Serial.println(F(" hPa"));
        
        // Vérifier les limites de pression
        if (pressure < PRESSURE_MIN || pressure > PRESSURE_MAX) {
            ERREUR = 1;  // Définir ERREUR à 1 si la pression est hors limites
        }
    }
}
