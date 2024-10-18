#include "Modes.h" // Inclure le fichier d'en-tête
#include "ChainableLED.h" // Assurez-vous d'inclure les bibliothèques nécessaires
#include "./LED/LED_control.h"


// Déclaration des variables pour gérer les états des modes
Mode currentMode = MODE_STANDARD; // Mode par défaut

// Variables pour l'état précédent des boutons
bool lastButton1State = HIGH; // Bouton 1 (mode Économie)
bool lastButton2State = HIGH; // Bouton 2 (mode Maintenance)

// Fonction d'initialisation des modes
void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);  // Bouton 1 pour mode Économie
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);  // Bouton 2 pour mode Maintenance
}

// Fonction de mise à jour des modes en fonction des boutons
void updateModes() {
    // Lire l'état actuel des boutons
    bool button1State = digitalRead(BUTTON_1_PIN);
    bool button2State = digitalRead(BUTTON_2_PIN);

    // Vérifier si les deux boutons sont pressés
    if (button1State == LOW && button2State == LOW) {
        currentMode = MODE_STANDARD; // Passer au mode Standard
    } 
    // Vérifier si le bouton 1 a été pressé
    else if (lastButton1State == HIGH && button1State == LOW) {
        currentMode = MODE_ECONOMY; // Passer au mode Économie
        setLEDColor(0, 0, 255); // LED bleue
    } 
    // Vérifier si le bouton 2 a été pressé
    else if (lastButton2State == HIGH && button2State == LOW) {
        currentMode = MODE_MAINTENANCE; // Passer au mode Maintenance
    } 
    // Ne pas revenir au mode standard tant qu'aucun bouton n'est pressé
    else {
        switch (currentMode) {
            case MODE_STANDARD:
                setLEDColor(0, 255, 0); // LED verte
                break;
            case MODE_ECONOMY:
                // Gérer le mode Économie si besoin
                break;
            case MODE_MAINTENANCE:
                // Gérer le mode Maintenance si besoin
                break;
        }
    }

    // Mettre à jour l'état précédent des boutons
    lastButton1State = button1State;
    lastButton2State = button2State;
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
    setLEDColor(255, 128, 0); // LED verte
}