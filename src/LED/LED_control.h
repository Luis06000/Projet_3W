#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "ChainableLED.h"

// Déclaration des constantes et variables
constexpr uint8_t NUM_LEDS = 5;

// Déclaration de l'objet leds
extern ChainableLED leds;

// Déclaration des fonctions
void initLEDs();
void setLEDColor(uint8_t r, uint8_t g, uint8_t b);

#endif // LED_CONTROL_H

