#include "LightSensor.h"
#include "Config.h"
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
    light = analogRead(lightSensorPin);
    
    if (light < params.LUMIN_LOW || light > params.LUMIN_HIGH) {
        ERREUR = 1;  // Définir ERREUR à 1 si l'humidité est hors limites
    }
    return light;
}
