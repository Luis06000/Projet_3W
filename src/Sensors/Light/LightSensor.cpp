#include "LightSensor.h"
#include <Arduino.h>

// Constructeur par défaut
LightSensor::LightSensor() {}

// Initialiser le capteur de lumière
bool LightSensor::begin() {
    pinMode(lightSensorPin, INPUT_PULLUP);
    return true;
}

// Vérifier si le capteur est en marche fonctionnement
bool LightSensor::isRunning() {
    return true;
}

// Afficher la valeur actuelle du capteur de lumière
int LightSensor::LightValue() {
    return analogRead(lightSensorPin);
}
