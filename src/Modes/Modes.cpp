#include "Modes.h" // Inclure le fichier d'en-tête
#include "ChainableLED.h" // Assurez-vous d'inclure les bibliothèques nécessaires
#include "./LED/LED_control.h"

// Déclaration des variables pour gérer les états des modes
Mode currentMode = MODE_STANDARD; // Mode par défaut

// Fonction d'initialisation des modes
void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);  // Bouton 1 pour mode Économie
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);  // Bouton 2 pour mode Maintenance
}

// Fonction de mise à jour des modes en fonction des boutons
void updateModes() {
    if (digitalRead(BUTTON_1_PIN) == LOW) {
        currentMode = MODE_ECONOMY; // Passer au mode Économie
        setLEDColor(255, 0, 0); // LED rouge
    } 
    else if (digitalRead(BUTTON_2_PIN) == LOW) {
        currentMode = MODE_MAINTENANCE; // Passer au mode Maintenance
    } 
    else {
        currentMode = MODE_STANDARD; // Rester en mode Standard
        setLEDColor(0, 255, 0); // LED verte
    }
}

// Fonction pour le mode Standard
void modeStandard() {
    // Mode par défaut, acquisition des données
}

// Fonction pour le mode Économie
void modeEconomy() {
    // Réduction de la fréquence des acquisitions pour économiser l'énergie
}

// Fonction pour le mode Maintenance
void modeMaintenance() {
    static unsigned long lastTime = 0;
    static bool ledState = false;
    unsigned long currentTime = millis();

    // Clignoter toutes les 500 ms
    if (currentTime - lastTime >= 500) {
        lastTime = currentTime;
        ledState = !ledState;

        if (ledState) {
            setLEDColor(255, 0, 0); // LED rouge
        } else {
            setLEDColor(0, 255, 0); // LED verte
        }
    }
}