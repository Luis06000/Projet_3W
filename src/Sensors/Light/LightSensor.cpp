// #include "Wire.h"
// #include <SPI.h>
// #include "AsyncDelay.h"
// #include "ChainableLED.h"

// #define NUM_LEDS  1  // Nombre de LEDs
// #define LIGHT_SENSOR_PIN A0  // Pin pour le capteur de lumière
// #define LED_PIN_D7 7  // Pin pour la LED Chainable connectée à D7

// ChainableLED leds(LED_PIN_D7, LED_PIN_D7 + 1, NUM_LEDS);  // Initialiser la LED branchée à D7

// int lightThreshold = 300;  // Seuil pour déterminer la présence de lumière

// void setup() {
//   Serial.begin(9600);  // Initialiser la communication série
//   pinMode(LIGHT_SENSOR_PIN, INPUT);  // Configurer le capteur de lumière comme entrée
// }

// void loop() {
//   // Lire la valeur du capteur de lumière
//   int lightValue = analogRead(LIGHT_SENSOR_PIN);

//   // Afficher la valeur du capteur sur le Moniteur Série
//   Serial.print("Valeur du capteur de lumière: ");
//   Serial.println(lightValue);

//   // Vérifier la valeur du capteur pour changer la couleur de la LED
//   if (lightValue > lightThreshold) {
//     // Lumière détectée, LED en vert
//     leds.setColorRGB(0, 0, 255, 0);  // Vert
//   } else {
//     // Pas de lumière, LED en rouge
//     leds.setColorRGB(0, 255, 0, 0);  // Rouge
//   }

//   delay(500);  // Attendre un peu avant de refaire une lecture
// }



#include "LightSensor.h"
#include <Arduino.h>

LightSensor::LightSensor(int lightPin, int threshold)
    : lightSensorPin(lightPin), lightThreshold(threshold) {}

void LightSensor::setup() {
    pinMode(lightSensorPin, INPUT);
}

void LightSensor::loop() {
    int lightValue = analogRead(lightSensorPin);

    Serial.print("Valeur du capteur de lumière: ");
    Serial.println(lightValue);

    delay(500);
}
