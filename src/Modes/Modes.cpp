#include "Modes.h"
#include "./LED/LED_control.h"
#include "./Buttons/Button_control.h"

Mode currentMode = MODE_STANDARD; // Mode par défaut

// Variables pour l'état précédent des boutons
bool lastButton1State = HIGH; // Bouton 1 (vert)
bool lastButton2State = HIGH; // Bouton 2 (rouge)

// Variables pour le chronométrage des boutons
unsigned long button1PressTime = 0;  // Chronomètre pour le bouton 1 (Économie)
unsigned long button2PressTime = 0;  // Chronomètre pour le bouton 2 (Maintenance et retour Standard)
unsigned long lastActivityTime = 0;  // Chronomètre pour l'inactivité dans le mode Configuration
const unsigned long buttonHoldDuration = 5000; // 5 secondes
const unsigned long inactivityDuration = 1800000; // 30 minutes d'inactivité

// Fonction d'initialisation des modes
void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);

    // Vérifier si le bouton 2 (bouton rouge) est pressé au démarrage
    if (digitalRead(BUTTON_2_PIN) == LOW) {
        currentMode = MODE_CONFIGURATION; // Passer en mode Configuration si le bouton rouge est appuyé au démarrage
        setLEDColor(255, 255, 0); // LED jaune
        lastActivityTime = millis(); // Démarre le compteur d'inactivité
        return;
    } else {
        currentMode = MODE_STANDARD; // Passer en mode Standard si le bouton rouge n'est pas pressé
        setLEDColor(0, 255, 0); // LED verte
    }
}

// Fonction de mise à jour des modes en fonction des boutons
void updateModes() {
    // Lire l'état actuel des boutons
    bool button1State = digitalRead(BUTTON_1_PIN);
    bool button2State = digitalRead(BUTTON_2_PIN);

    // Gestion du mode Configuration et de l'inactivité
    if (currentMode == MODE_CONFIGURATION) {
        // Si aucune activité pendant 1 minute, passer en mode Standard
        if (millis() - lastActivityTime >= inactivityDuration) {
            currentMode = MODE_STANDARD;
            setLEDColor(0, 255, 0); // LED verte
            return;
        }
        return;
    }

    // Gestion du bouton 1 (pour entrer en mode Économie après 5 secondes)
    if (button1State == LOW && lastButton1State == HIGH) {
        button1PressTime = millis(); // Enregistre l'heure à laquelle le bouton a été pressé
        lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
    }

    if (button1State == LOW && (millis() - button1PressTime >= buttonHoldDuration)) {
        if (currentMode == MODE_STANDARD) {
            currentMode = MODE_ECONOMY;
        }
        lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
    }

    if (button1State == HIGH && lastButton1State == LOW) {
        button1PressTime = 0; // Réinitialise le chronomètre
    }

    // Gestion du bouton 2 (pour entrer en mode Maintenance après 5 secondes ou revenir au mode Standard depuis Économie)
    if (button2State == LOW && lastButton2State == HIGH) {
        button2PressTime = millis(); // Enregistre l'heure à laquelle le bouton a été pressé
        lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
    }

    if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration)) {
        if (currentMode == MODE_STANDARD) {
            currentMode = MODE_MAINTENANCE; // Revenir au mode Standard si en mode Économie
        } else if (currentMode == MODE_ECONOMY) {
            currentMode = MODE_MAINTENANCE; // Passer au mode Maintenance si pas en mode Économie
        } else if (currentMode == MODE_CONFIGURATION) {
            currentMode = MODE_STANDARD; // Passer au mode Maintenance si pas en mode Économie
        }
        lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
    }

    if (button2State == HIGH && lastButton2State == LOW) {
        button2PressTime = 0; // Réinitialise le chronomètre
    }

    // Mettre à jour l'état précédent des boutons
    lastButton1State = button1State;
    lastButton2State = button2State;

    switch (currentMode) {
        case MODE_STANDARD:
            setLEDColor(0, 255, 0); // LED verte
            break;
        case MODE_ECONOMY:
            setLEDColor(0, 0, 255); // LED bleue
            break;
        case MODE_MAINTENANCE:
            setLEDColor(255, 128, 0); // LED orange
            break;
        case MODE_CONFIGURATION:
            setLEDColor(255, 255, 0); // LED jaune
            break;
    }
}

