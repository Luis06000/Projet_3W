#include "Modes.h"
#include "./LED/LED_control.h"
#include "./Buttons/Button_control.h"

// Déclaration des variables pour gérer les états des modes
Mode currentMode = MODE_STANDARD; // Mode par défaut

// Variables pour l'état précédent des boutons
bool lastButton1State = HIGH; // Bouton 1 (mode Économie)
bool lastButton2State = HIGH; // Bouton 2 (mode Maintenance)


// Fonction d'initialisation des modes
void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);  // Bouton 1 pour mode Économie
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);  // Bouton 2 pour mode Maintenance

    // Vérifier si le bouton 2 (bouton rouge) est pressé au démarrage
    if (digitalRead(BUTTON_2_PIN) == LOW) {
        currentMode = MODE_CONFIGURATION; // Passer en mode Configuration si le bouton rouge est appuyé au démarrage
        setLEDColor(255, 0, 0); // LED rouge
    } else {
        currentMode = MODE_STANDARD; // Passer en mode Standard si le bouton rouge n'est pas pressé
        setLEDColor(0, 255, 0); // LED verte
    }
}

// Fonction de mise à jour des modes en fonction des boutons
void updateModes() {
    // Vérifier que le mode ne peut pas changer une fois que le mode standard est atteint
    if (currentMode == MODE_CONFIGURATION) {
        return; // Ne pas changer de mode
    }

    // Lire l'état actuel des boutons
    bool button1State = digitalRead(BUTTON_1_PIN);
    bool button2State = digitalRead(BUTTON_2_PIN);

    // Vérifier si le bouton 1 a été pressé
    if (lastButton1State == HIGH && button1State == LOW) {
        currentMode = MODE_ECONOMY; // Passer au mode Économie
    } 
    // Vérifier si le bouton 2 a été pressé
    else if (lastButton2State == HIGH && button2State == LOW) {
        currentMode = MODE_MAINTENANCE; // Passer au mode Maintenance
    } 
    // else if (button2State == LOW && button1State == LOW) {
    //     currentMode = MODE_STANDARD; // Passer au mode standard
    // } 

    // Mettre à jour l'état précédent des boutons
    lastButton1State = button1State;
    lastButton2State = button2State;

    // Mettre à jour la couleur de la LED selon le mode courant
    switch (currentMode) {
        case MODE_STANDARD:
            setLEDColor(0, 255, 0); // LED verte
            break;
        case MODE_ECONOMY:
            setLEDColor(0, 0, 255); // LED bleue
            if (button2State == LOW && button1State == LOW) {
                currentMode = MODE_STANDARD; // Passer au mode standard
            } 
            break;
        case MODE_MAINTENANCE:
            setLEDColor(255, 128, 0); // LED orange
            break;
        case MODE_CONFIGURATION:
            setLEDColor(255, 0, 0); // LED rouge
            break;
    }
}

// Fonction pour le mode Standard
void modeStandard() {
    // Logique spécifique au mode Standard
}

// Fonction pour le mode Économie
void modeEconomique() {
    // Logique spécifique au mode Économie
}

// Fonction pour le mode Maintenance
void modeMaintenance() {
    setLEDColor(255, 128, 0); // LED orange pour le mode Maintenance
}

// Fonction pour le mode Configuration
void modeConfiguration() {
    // Logique spécifique au mode Configuration
}
