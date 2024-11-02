#include "Button_control.h"
#include <Arduino.h>

// Variables globales pour l'état des boutons et la gestion du debounce
volatile bool ledOn = false;
volatile bool buttonPressed = false;
const unsigned long debounceDelay = 50;  // Délai pour éviter les rebonds
volatile unsigned long lastDebounceTime1 = 0;
volatile unsigned long lastDebounceTime2 = 0;

void initButtons() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);  // Utilisation de la résistance pull-up interne
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);

    // Attacher les interruptions pour chaque bouton
    attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Interrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Interrupt, FALLING);
}

void button1Interrupt() {
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime1 > debounceDelay) {
        buttonPressed = true;
        ledOn = true;  // Allumer la LED quand le bouton 1 est pressé
        lastDebounceTime1 = currentTime;  // Mettre à jour le dernier temps de debounce
    }
}

void button2Interrupt() {
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime2 > debounceDelay) {
        buttonPressed = true;
        ledOn = false;  // Éteindre la LED quand le bouton 2 est pressé
        lastDebounceTime2 = currentTime;  // Mettre à jour le dernier temps de debounce
    }
}
