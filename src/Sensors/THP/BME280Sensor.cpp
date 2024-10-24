#include "BME280Sensor.h"
#include <Wire.h>
#include <SPI.h>

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

// Variable pour suivre le temps écoulé
unsigned long lastBME280ReadTime = 0;
const unsigned long bme280ReadInterval = 60000;  // Intervalle de 60 secondes

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

void BME280Sensor::readSensor() {
    // Vérifier si 60 secondes se sont écoulées depuis la dernière lecture
    if (millis() - lastBME280ReadTime >= bme280ReadInterval) {
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
