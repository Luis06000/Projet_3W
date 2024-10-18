#include "BME280Sensor.h"
#include <Wire.h>
#include <SPI.h>

#define SEALEVELPRESSURE_HPA (1013.25)  // Pression au niveau de la mer

BME280Sensor::BME280Sensor() {}

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

void BME280Sensor::readSensor() {
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F;  // Convertir en hPa
    altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

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

    Serial.print("Altitude approximative : ");
    Serial.print(altitude);
    Serial.println(" m");

    Serial.println();
}