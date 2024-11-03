#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

#include <Arduino.h>

// Pins des boutons
#define BUTTON_1_PIN 3
#define BUTTON_2_PIN 4

// Structure de contrôle des boutons
struct ButtonControl {
    static uint8_t status;
    static uint8_t debounceCount;
};

// Bits de status
#define BTN_1_PRESSED   0x01
#define BTN_2_PRESSED   0x02
#define BTN_1_DEBOUNCE  0x04
#define BTN_2_DEBOUNCE  0x08

// Fonctions
void initButtons();
void button1Interrupt();
void button2Interrupt();
bool isButton1Pressed();
bool isButton2Pressed();

#endif