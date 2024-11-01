// #include "Modes.h"
// #include "Config.h"
// #include "./LED/LED_control.h"
// #include "./Buttons/Button_control.h"

// // Déclarations externes et constantes
// Mode currentMode = MODE_STANDARD;
// Mode previousMode = MODE_STANDARD;

// bool lastButton1State = HIGH, lastButton2State = HIGH;
// unsigned long button1PressTime = 0, button2PressTime = 0, lastActivityTime = 0;
// const unsigned long buttonHoldDuration = 5000, inactivityDuration = 1800000;

// // Simplification des drapeaux de verrouillage
// bool button1Lock = false, button2Lock = false;

// // Affichage et paramétrage des LED en fonction des modes
// void setMode(Mode mode, int r, int g, int b) {
//     currentMode = mode;
//     setLEDColor(r, g, b);
// }

// void modeConfiguration() {
//     Serial.println(F("Mode Configuration : Entrez le nom du paramètre et la valeur (exemple : LOG_INTERVALL 2)"));
//     button2Lock = false;  // Réinitialise le verrouillage du bouton 2 dans ce mode

//     while (true) {
//         // Vérifie si un paramètre est entré
//         if (Serial.available() > 0) {
//             String paramName = Serial.readStringUntil(' ');
//             unsigned long paramValue = Serial.parseInt();
//             updateConfigParameter(paramName, paramValue);

//             lastActivityTime = millis();
//         }

//         // Gérer l'inactivité
//         if (millis() - lastActivityTime >= inactivityDuration) {
//             setMode(MODE_STANDARD, 0, 255, 0); // LED verte
//             return;
//         }

//         // Vérification du bouton 2 pour revenir au mode standard
//         bool button2State = digitalRead(BUTTON_2_PIN);
//         if (button2State == LOW && lastButton2State == HIGH) {
//             button2PressTime = millis();
//             button2Lock = false;
//         }
//         if (button2State == LOW && millis() - button2PressTime >= buttonHoldDuration && !button2Lock) {
//             setMode(MODE_STANDARD, 0, 255, 0); // LED verte
//             button2Lock = true;
//             return;
//         }

//         lastButton2State = button2State;
//     }
// }

// void initModes() {
//     pinMode(BUTTON_1_PIN, INPUT_PULLUP);
//     pinMode(BUTTON_2_PIN, INPUT_PULLUP);

//     if (digitalRead(BUTTON_2_PIN) == LOW) {
//         setMode(MODE_CONFIGURATION, 255, 255, 0); // LED jaune
//         delay(2000);
//         modeConfiguration();
//     } else {
//         setMode(MODE_STANDARD, 0, 255, 0); // LED verte
//     }
// }

// void updateModes() {
//     bool button1State = digitalRead(BUTTON_1_PIN);
//     bool button2State = digitalRead(BUTTON_2_PIN);

//     // Transition entre Mode Standard et Mode Économie
//     if (button1State == LOW && lastButton1State == HIGH) {
//         button1PressTime = millis();
//         button1Lock = false;
//     }

//     if (button1State == LOW && millis() - button1PressTime >= buttonHoldDuration && !button1Lock) {
//         if (currentMode == MODE_STANDARD) setMode(MODE_ECONOMY, 0, 0, 255); // LED bleue
//         else if (currentMode == MODE_ECONOMY) setMode(MODE_STANDARD, 0, 255, 0); // LED verte
//         button1Lock = true;
//     }

//     if (button1State == HIGH) button1Lock = false;

//     // Transition entre Mode Standard/Économie et Mode Maintenance
//     if (button2State == LOW && lastButton2State == HIGH) {
//         button2PressTime = millis();
//         button2Lock = false;
//     }

//     if (button2State == LOW && millis() - button2PressTime >= buttonHoldDuration && !button2Lock) {
//         if (currentMode == MODE_MAINTENANCE) {
//             setMode(previousMode, previousMode == MODE_STANDARD ? 0 : 0, previousMode == MODE_STANDARD ? 255 : 0, previousMode == MODE_STANDARD ? 0 : 255);
//         } else {
//             previousMode = currentMode;
//             setMode(MODE_MAINTENANCE, 255, 128, 0); // LED orange
//         }
//         button2Lock = true;
//     }

//     if (button2State == HIGH) button2Lock = false;

//     lastButton1State = button1State;
//     lastButton2State = button2State;
// }




#include "Modes.h"
#include "Config.h"
#include "./LED/LED_control.h"
#include "./Buttons/Button_control.h"

// Déclarations externes et constantes
Mode currentMode = MODE_STANDARD;
Mode previousMode = MODE_STANDARD;

bool lastButton1State = HIGH, lastButton2State = HIGH;
unsigned long button1PressTime = 0, button2PressTime = 0, lastActivityTime = 0;
const unsigned long buttonHoldDuration = 5000, inactivityDuration = 1800000;

// Simplification des drapeaux de verrouillage
bool button1Lock = false, button2Lock = false;
bool configModeLock = false; // Verrouillage pour le mode configuration

void toUppercase(String &str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}

// Affichage et paramétrage des LED en fonction des modes
void setMode(Mode mode, int r, int g, int b) {
    currentMode = mode;
    setLEDColor(r, g, b);
}

void modeConfiguration() {
    Serial.println(F("Mode Configuration : Entrez le nom du paramètre et la valeur séparés par un espace"));
    bool button2State;

    configModeLock = true; // Verrouille le mode configuration
    while (true) {
        if (Serial.available() > 0) {
            String paramName = Serial.readStringUntil(' ');
            toUppercase(paramName);
            unsigned long paramValue = Serial.parseInt();
            updateConfigParameter(paramName, paramValue);
            lastActivityTime = 0; // Reset last activity time
        }
    
        // Vérification de l'inactivité
        if (millis() - lastActivityTime >= inactivityDuration) {
            setMode(MODE_STANDARD, 0, 255, 0); // LED verte
            return; // Sort de la fonction
        }
    
        // Gestion des boutons
        button2State = digitalRead(BUTTON_2_PIN);
        if (button2State == LOW && lastButton2State == HIGH) button2PressTime = millis();
        if (button2State == LOW && millis() - button2PressTime >= buttonHoldDuration && !button2Lock) {
            setMode(MODE_STANDARD, 0, 255, 0); // LED verte
            button2Lock = true;
            return;
        }
        lastButton2State = button2State;
    }
}

void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);

    if (digitalRead(BUTTON_2_PIN) == LOW) {
        setMode(MODE_CONFIGURATION, 255, 255, 0); // LED jaune
        delay(2000);
        modeConfiguration();
    } else {
        setMode(MODE_STANDARD, 0, 255, 0); // LED verte
    }
}

void updateModes() {
    bool button1State = digitalRead(BUTTON_1_PIN);
    bool button2State = digitalRead(BUTTON_2_PIN);

    // Transition entre Mode Standard et Mode Économie
    if (button1State == LOW && lastButton1State == HIGH) {
        button1PressTime = millis();
        button1Lock = false;
    }

    if (button1State == LOW && millis() - button1PressTime >= buttonHoldDuration && !button1Lock) {
        if (currentMode == MODE_STANDARD) setMode(MODE_ECONOMY, 0, 0, 255); // LED bleue
        else if (currentMode == MODE_ECONOMY) setMode(MODE_STANDARD, 0, 255, 0); // LED verte
        button1Lock = true;
    }

    if (button1State == HIGH) button1Lock = false;

    // Transition entre Mode Standard/Économie et Mode Maintenance
    if (button2State == LOW && lastButton2State == HIGH) {
        button2PressTime = millis();
        button2Lock = false;
    }

    if (button2State == LOW && millis() - button2PressTime >= buttonHoldDuration && !button2Lock) {
        if (currentMode == MODE_MAINTENANCE) {
            setMode(previousMode, previousMode == MODE_STANDARD ? 0 : 0, previousMode == MODE_STANDARD ? 255 : 0, previousMode == MODE_STANDARD ? 0 : 255);
        } else {
            previousMode = currentMode;
            setMode(MODE_MAINTENANCE, 255, 128, 0); // LED orange
        }
        button2Lock = true;
    }

    if (button2State == HIGH) button2Lock = false;

    lastButton1State = button1State;
    lastButton2State = button2State;
}
