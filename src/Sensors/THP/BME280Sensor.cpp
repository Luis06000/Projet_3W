#include "BME280Sensor.h"
#include <Wire.h>
#include <SPI.h>
#include "Config.h"

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

// Variable pour suivre le temps écoulé
unsigned long lastBME280ReadTime = 0;

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

void BME280Sensor::readSensor() {
    // Vérifier si le délai s'est écoulé depuis la dernière lecture
    if (millis() - lastBME280ReadTime >= LOG_INTERVAL) {
        // Met à jour le temps de la dernière lecture
        lastBME280ReadTime = millis();

        // Lire les données du capteur BME280
        temperature = bme.readTemperature();
        humidity = bme.readHumidity();
        pressure = bme.readPressure() / 100.0F;  // Convertir en hPa

        // Afficher les valeurs dans le Moniteur Série
        Serial.print("Température : ");
        Serial.print(temperature);
        Serial.println(" °C");

        Serial.print("Humidité : ");
        Serial.print(humidity);
        Serial.println(" %");

        Serial.print("Pression : ");
        Serial.print(pressure);
        Serial.println(" hPa");
    }
}
