#include "Button_control.h"

// Initialisation des variables statiques
uint8_t ButtonControl::status = 0;
uint8_t ButtonControl::debounceCount = 0;

// Constantes
static const uint8_t DEBOUNCE_THRESHOLD = 5;

void initButtons() {
    // Configuration des pins
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Interrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Interrupt, FALLING);
}

void button1Interrupt() {
    if (!(ButtonControl::status & BTN_1_DEBOUNCE)) {
        ButtonControl::status |= BTN_1_PRESSED | BTN_1_DEBOUNCE;
        ButtonControl::debounceCount = DEBOUNCE_THRESHOLD;
    }
}

void button2Interrupt() {
    if (!(ButtonControl::status & BTN_2_DEBOUNCE)) {
        ButtonControl::status |= BTN_2_PRESSED | BTN_2_DEBOUNCE;
        ButtonControl::debounceCount = DEBOUNCE_THRESHOLD;
    }
}

// Fonctions utilitaires
bool isButton1Pressed() {
    bool pressed = ButtonControl::status & BTN_1_PRESSED;
    ButtonControl::status &= ~BTN_1_PRESSED;
    return pressed;
}

bool isButton2Pressed() {
    bool pressed = ButtonControl::status & BTN_2_PRESSED;
    ButtonControl::status &= ~BTN_2_PRESSED;
    return pressed;
}

// Fonction à appeler dans la boucle principale pour gérer le debounce
void updateButtons() {
    if (ButtonControl::debounceCount > 0) {
        ButtonControl::debounceCount--;
        if (ButtonControl::debounceCount == 0) {
            ButtonControl::status &= ~(BTN_1_DEBOUNCE | BTN_2_DEBOUNCE);
        }
    }
}