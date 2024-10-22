// #ifndef LED_CONTROL_H
// #define LED_CONTROL_H

// #include "ChainableLED.h"

// // Déclaration des constantes et variables
// #define NUM_LEDS 5
// #define BUTTON_1_PIN 2
// #define BUTTON_2_PIN 3

// // Déclaration de l'objet leds
// extern ChainableLED leds;

// // Déclaration des fonctions
// void initLEDs();
// void updateLEDs();

// // Déclaration de la fonction pour régler la couleur de la LED
// void setLEDColor(int r, int g, int b);

// #endif // LED_CONTROL_H




#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "ChainableLED.h"

// Déclaration des constantes et variables
#define NUM_LEDS 5

// Déclaration de l'objet leds
extern ChainableLED leds;
extern volatile bool ledOn;

// Déclaration des fonctions
void initLEDs();
void updateLEDs();
void setLEDColor(int r, int g, int b);

#endif // LED_CONTROL_H

