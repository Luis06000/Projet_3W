// #include "Modes.h"
// #include "Config.h"
// #include "./LED/LED_control.h"
// #include "./Buttons/Button_control.h"

// Mode currentMode = MODE_STANDARD; // Mode par défaut
// Mode previousMode = MODE_STANDARD; // Stocke le mode précédent avant de passer en mode Maintenance

// // Variables pour l'état précédent des boutons
// bool lastButton1State = HIGH; // Bouton 1 (vert)
// bool lastButton2State = HIGH; // Bouton 2 (rouge)

// // Variables pour le chronométrage des boutons
// unsigned long button1PressTime = 0;  // Chronomètre pour le bouton 1 (Économie)
// unsigned long button2PressTime = 0;  // Chronomètre pour le bouton 2 (Maintenance et retour Standard/Économie)
// unsigned long lastActivityTime = 0;  // Chronomètre pour l'inactivité dans le mode Configuration
// const unsigned long buttonHoldDuration = 5000; // 5 secondes
// const unsigned long inactivityDuration = 1800000; // 30 minutes d'inactivité

// // Variables pour empêcher la LED de clignoter
// bool modeChanged = false; // Empêche de changer de mode plusieurs fois tant que le bouton est maintenu


// void mode_configuration() {
//     Serial.println(F("Mode Configuration : Entrez le nom du paramètre et la valeur (exemple : LOG_INTERVALL 2)"));
//     bool button2State;

//     while (true) {
//         // Vérifier si l'utilisateur a entré un paramètre
//         if (Serial.available() > 0) {
//             // Lire le nom et la valeur depuis le Moniteur Série
//             String paramName = Serial.readStringUntil(' ');  // Lire jusqu'à l'espace pour le nom du paramètre
//             unsigned long paramValue = Serial.parseInt();    // Lire la valeur en tant que nombre entier

//             // Appeler la fonction de mise à jour
//             updateConfigParameter(paramName, paramValue);

//             // Afficher le résultat
//             Serial.print("Paramètre ");
//             Serial.print(paramName);
//             Serial.print(" mis à jour avec la valeur ");
//             Serial.println(paramValue);
//         }

//         // Vérifier l'état du bouton rouge pour sortir du mode Configuration
//         button2State = digitalRead(BUTTON_2_PIN);

//         if (button2State == LOW && lastButton2State == HIGH) {
//             button2PressTime = millis(); // Commence le chronomètre
//         }
//         if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration)) {
//             // Si le bouton rouge est maintenu pendant 5 secondes, passer en mode Standard
//             button2PressTime = 0; // Réinitialise le chronomètre
//             currentMode = MODE_STANDARD;
//             modeChanged = true; // Marquer que le mode a changé
//             setLEDColor(0, 255, 0); // LED verte pour le mode Standard
//             return; // Quitter la fonction pour retourner au mode Standard
//         }

//         lastButton2State = button2State; // Mettre à jour l'état précédent
//     }
// }



// // Fonction d'initialisation des modes
// void initModes() {
//     pinMode(BUTTON_1_PIN, INPUT_PULLUP);
//     pinMode(BUTTON_2_PIN, INPUT_PULLUP);

//     // Vérifier si le bouton 2 (bouton rouge) est pressé au démarrage
//     if (digitalRead(BUTTON_2_PIN) == LOW) {
//         // On passe directement en mode Configuration
//         currentMode = MODE_CONFIGURATION;
//         setLEDColor(255, 255, 0); // LED jaune
//         lastActivityTime = millis(); // Démarre le compteur d'inactivité
//         delay(2000);  // Délai court pour éviter les oscillations
//         mode_configuration();
//         return;
//     } else {
//         // Passer en mode Standard si le bouton rouge n'est pas pressé au démarrage
//         currentMode = MODE_STANDARD;
//         setLEDColor(0, 255, 0); // LED verte
//     }
// }


// // Fonction de mise à jour des modes en fonction des boutons
// void updateModes() {

//     // Lire l'état actuel des boutons
//     bool button1State = digitalRead(BUTTON_1_PIN);
//     bool button2State = digitalRead(BUTTON_2_PIN);
//     // Gestion du mode Configuration et de l'inactivité
//     if (currentMode == MODE_CONFIGURATION) {
//         // Si aucune activité pendant 30 minutes, passer en mode Standard
//         if (millis() - lastActivityTime >= inactivityDuration) {
//             currentMode = MODE_STANDARD;
//             setLEDColor(0, 255, 0); // LED verte
//             return;
//         }

//         // Si le bouton rouge est maintenu pendant 5 secondes, revenir en mode Standard
//         if (button2State == LOW && lastButton2State == HIGH) {
//             button2PressTime = millis(); // Enregistre l'heure à laquelle le bouton a été pressé
//         }

//         if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration)) {
//             currentMode = MODE_STANDARD;
//             setLEDColor(0, 255, 0); // LED verte
//             lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
//             modeChanged = true; // Marquer que le mode a changé
//             return;
//         }

//         // Si le bouton est relâché, réinitialiser le chronomètre
//         if (button2State == HIGH && lastButton2State == LOW) {
//             button2PressTime = 0; // Réinitialise le chronomètre
//             modeChanged = false; // Réinitialiser le flag de changement de mode
//         }

//         // Mettre à jour l'état précédent des boutons
//         lastButton1State = button1State;
//         lastButton2State = button2State;

//         return; // Ne pas exécuter le reste de la fonction si en mode Configuration
//     }

//     // Gestion du bouton 1 (pour entrer en mode Économie après 5 secondes)
//     if (button1State == LOW && lastButton1State == HIGH) {
//         button1PressTime = millis(); // Enregistre l'heure à laquelle le bouton a été pressé
//         lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
//         modeChanged = false; // Réinitialiser le flag de changement de mode
//     }

//     // Si le bouton est maintenu pendant 5 secondes, passer en mode Économie ou Standard
//     if (button1State == LOW && (millis() - button1PressTime >= buttonHoldDuration) && !modeChanged) {
//         if (currentMode == MODE_STANDARD) {
//             previousMode = currentMode; // Sauvegarde du mode précédent
//             currentMode = MODE_ECONOMY;
//             setLEDColor(0, 0, 255); // LED bleue une fois le mode économique activé
//         } else if (currentMode == MODE_ECONOMY) {
//             previousMode = currentMode; // Sauvegarde du mode précédent
//             currentMode = MODE_STANDARD;
//             setLEDColor(0, 255, 0); // LED verte une fois de retour en mode standard
//         }
//         modeChanged = true; // Marquer que le mode a changé
//         lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
//     }

//     // Si le bouton est relâché, réinitialiser le chronomètre
//     if (button1State == HIGH && lastButton1State == LOW) {
//         button1PressTime = 0; // Réinitialise le chronomètre
//         modeChanged = false; // Réinitialiser le flag de changement de mode
//     }

//     // Gestion du bouton 2 (pour entrer en mode Maintenance après 5 secondes ou revenir au mode précédent)
//     if (button2State == LOW && lastButton2State == HIGH) {
//         button2PressTime = millis(); // Enregistre l'heure à laquelle le bouton a été pressé
//         lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
//         modeChanged = false; // Réinitialiser le flag de changement de mode
//     }

//     if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration) && !modeChanged) {
//         if (currentMode == MODE_MAINTENANCE) {
//             // Revenir au mode précédent (Standard ou Économie) si en mode Maintenance
//             currentMode = previousMode; // Récupère le mode précédent (Standard ou Économie)
//             if (previousMode == MODE_STANDARD) {
//                 setLEDColor(0, 255, 0); // LED verte
//             } else if (previousMode == MODE_ECONOMY) {
//                 setLEDColor(0, 0, 255); // LED bleue
//             }
//         } else {
//             previousMode = currentMode; // Sauvegarde du mode actuel avant de passer en mode Maintenance
//             currentMode = MODE_MAINTENANCE; // Passer en mode Maintenance
//             setLEDColor(255, 128, 0); // LED orange
//         }
//         modeChanged = true; // Marquer que le mode a changé
//         lastActivityTime = millis(); // Réinitialise le chronomètre d'inactivité
//     }

//     if (button2State == HIGH && lastButton2State == LOW) {
//         button2PressTime = 0; // Réinitialise le chronomètre
//         modeChanged = false; // Réinitialiser le flag de changement de mode
//     }

//     // Mettre à jour l'état précédent des boutons
//     lastButton1State = button1State;
//     lastButton2State = button2State;

//     // Gestion du mode selon l'état actuel
//     switch (currentMode) {
//         case MODE_STANDARD:
//             setLEDColor(0, 255, 0); // LED verte
//             break;
//         case MODE_ECONOMY:
//             setLEDColor(0, 0, 255); // LED bleue
//             break;
//         case MODE_MAINTENANCE:
//             setLEDColor(255, 128, 0); // LED orange
//             break;
//         case MODE_CONFIGURATION:
//             setLEDColor(255, 255, 0); // LED jaune
//             break;
//     }
// }



















// #include "Modes.h"
// #include "Config.h"
// #include "./LED/LED_control.h"
// #include "./Buttons/Button_control.h"

// Mode currentMode = MODE_STANDARD; // Mode par défaut
// Mode previousMode = MODE_STANDARD; // Stocke le mode précédent avant de passer en mode Maintenance

// // État des boutons
// bool lastButton1State = HIGH;
// bool lastButton2State = HIGH;

// // Chronomètres pour les boutons
// unsigned long button1PressTime = 0;
// unsigned long button2PressTime = 0;
// unsigned long lastActivityTime = 0;
// const unsigned long buttonHoldDuration = 5000; // 5 secondes pour changer de mode
// const unsigned long inactivityDuration = 1800000; // 30 minutes d'inactivité

// // Variable de verrouillage de changement de mode
// bool modeLock = false;
// bool button1ModeLock = false;
// bool button2ModeLock = false;

// void mode_configuration() {
//     Serial.println(F("Mode Configuration : Entrez le nom du paramètre et la valeur (exemple : LOG_INTERVALL 2)"));
//     bool button2State;

//     while (true) {
//         // Vérifie si un paramètre est entré
//         if (Serial.available() > 0) {
//             String paramName = Serial.readStringUntil(' ');
//             unsigned long paramValue = Serial.parseInt();
//             updateConfigParameter(paramName, paramValue);

//             Serial.print("Paramètre ");
//             Serial.print(paramName);
//             Serial.print(" mis à jour avec la valeur ");
//             Serial.println(paramValue);
//         }

//         button2State = digitalRead(BUTTON_2_PIN);
//         if (button2State == LOW && lastButton2State == HIGH) {
//             button2PressTime = millis();
//         }
//         if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration)) {
//             currentMode = MODE_STANDARD;
//             setLEDColor(0, 255, 0);
//             modeLock = true;
//             return;
//         }

//         lastButton2State = button2State;
//     }
// }

// void initModes() {
//     pinMode(BUTTON_1_PIN, INPUT_PULLUP);
//     pinMode(BUTTON_2_PIN, INPUT_PULLUP);

//     if (digitalRead(BUTTON_2_PIN) == LOW) {
//         currentMode = MODE_CONFIGURATION;
//         setLEDColor(255, 255, 0); 
//         delay(2000);  
//         mode_configuration();
//     } else {
//         currentMode = MODE_STANDARD;
//         setLEDColor(0, 255, 0);
//     }
// }

// void updateModes() {
//     bool button1State = digitalRead(BUTTON_1_PIN);
//     bool button2State = digitalRead(BUTTON_2_PIN);

//     // Transition entre Mode Standard et Mode Économie
//     if (button1State == LOW && lastButton1State == HIGH) {
//         button1PressTime = millis();
//         button1ModeLock = false;
//     }

//     if (button1State == LOW && (millis() - button1PressTime >= buttonHoldDuration) && !button1ModeLock) {
//         if (currentMode == MODE_STANDARD) {
//             currentMode = MODE_ECONOMY;
//             setLEDColor(0, 0, 255); 
//         } else if (currentMode == MODE_ECONOMY) {
//             currentMode = MODE_STANDARD;
//             setLEDColor(0, 255, 0); 
//         }
//         button1ModeLock = true; 
//     }

//     if (button1State == HIGH) {
//         button1ModeLock = false;
//     }

//     // Transition entre Mode Standard/Économie et Mode Maintenance
//     if (button2State == LOW && lastButton2State == HIGH) {
//         button2PressTime = millis();
//         button2ModeLock = false;
//     }

//     if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration) && !button2ModeLock) {
//         if (currentMode == MODE_MAINTENANCE) {
//             currentMode = previousMode;
//             if (previousMode == MODE_STANDARD) {
//                 setLEDColor(0, 255, 0); 
//             } else if (previousMode == MODE_ECONOMY) {
//                 setLEDColor(0, 0, 255); 
//             }
//         } else {
//             previousMode = currentMode;
//             currentMode = MODE_MAINTENANCE;
//             setLEDColor(255, 128, 0);
//         }
//         button2ModeLock = true;
//     }

//     if (button2State == HIGH) {
//         button2ModeLock = false;
//     }

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

// Affichage et paramétrage des LED en fonction des modes
void setMode(Mode mode, int r, int g, int b) {
    currentMode = mode;
    setLEDColor(r, g, b);
}

void modeConfiguration() {
    Serial.println(F("Mode Configuration : Entrez le nom du paramètre et la valeur (exemple : LOG_INTERVALL 2)"));
    bool button2State;

    while (true) {
        if (Serial.available() > 0) {
            String paramName = Serial.readStringUntil(' ');
            unsigned long paramValue = Serial.parseInt();
            updateConfigParameter(paramName, paramValue);

            Serial.print(F("Paramètre "));
            Serial.print(paramName);
            Serial.print(F(" mis à jour avec la valeur "));
            Serial.println(paramValue);
        }

        button2State = digitalRead(BUTTON_2_PIN);
        if (button2State == LOW && lastButton2State == HIGH) button2PressTime = millis();
        if (button2State == LOW && millis() - button2PressTime >= buttonHoldDuration) {
            setMode(MODE_STANDARD, 0, 255, 0); // LED verte
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
