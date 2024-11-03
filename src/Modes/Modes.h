// #ifndef MODES_H
// #define MODES_H

// #include <Arduino.h>

// // Utiliser uint8_t au lieu de enum pour économiser de la mémoire
// #define MODE_STANDARD 0
// #define MODE_ECONOMY 1
// #define MODE_MAINTENANCE 2
// #define MODE_CONFIGURATION 3

// extern uint8_t currentMode;

// void initModes();
// void updateModes();
// void modeConfiguration();

// #endif // MODES_H




#ifndef MODES_H
#define MODES_H

#include <Arduino.h>

// Définition des modes comme constantes
#define MODE_STANDARD 0
#define MODE_ECONOMY 1
#define MODE_MAINTENANCE 2
#define MODE_CONFIGURATION 3

// Bits de statut pour les boutons
#define BTN_STATE_1     0x01
#define BTN_STATE_2     0x02
#define BTN_LOCK_1      0x04
#define BTN_LOCK_2      0x08
#define BTN_PRESSED_1   0x10
#define BTN_PRESSED_2   0x20

extern uint8_t currentMode;
extern uint8_t buttonStatus;

void initModes();
void updateModes();
void modeConfiguration();
void setMode(uint8_t mode, uint8_t r, uint8_t g, uint8_t b);

#endif