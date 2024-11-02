#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>

// Définition de la classe LightSensor
class LightSensor {
public:
    LightSensor();  // Constructeur
    bool begin();   // Initialiser le capteur de lumière
    bool isRunning();  // Vérifier si le capteur est en marche
    int LightValue();  // Afficher la valeur du capteur de lumière

private:
    int lightSensorPin = A0;
};

#endif // LIGHT_H
