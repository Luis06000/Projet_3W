#include "LightSensor.h"
#include <Arduino.h>
#include "Config.h"

// Constructeur par défaut
LightSensor::LightSensor() {}

// Variable pour suivre le temps écoulé
unsigned long lastLightPrintTime = 0;

// Initialiser le capteur de lumière
bool LightSensor::begin() {
    pinMode(lightSensorPin, INPUT_PULLUP);
    return true;
}

// Vérifier si le capteur est "en marche"
bool LightSensor::isRunning() {
    return true;
}

// Afficher la valeur actuelle du capteur de lumière
void LightSensor::printLightValue() {
    // Vérifier si le délai s'est écoulé depuis la dernière mesure
    if (millis() - lastLightPrintTime >= LOG_INTERVAL) {
        // Met à jour le temps du dernier affichage
        lastLightPrintTime = millis();

        // Lire la valeur du capteur
        int lightValue = analogRead(lightSensorPin);

        // Afficher la valeur du capteur de lumière
        Serial.print("\nValeur du capteur de lumière: ");
        Serial.println(lightValue);
    }
}
