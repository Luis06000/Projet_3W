#include "LightSensor.h"
#include <Arduino.h>

// Constructeur par défaut
LightSensor::LightSensor() {}

// Initialiser le capteur de lumière
bool LightSensor::begin() {
    pinMode(lightSensorPin, INPUT);
    return true;
}

// Vérifier si le capteur est "en marche"
bool LightSensor::isRunning() {
    return true;
}

// Afficher la valeur actuelle du capteur de lumière
void LightSensor::printLightValue() {
    int lightValue = analogRead(lightSensorPin);  // Lire la valeur du capteur

    Serial.print("Valeur du capteur de lumière: ");
    Serial.println(lightValue);

}
