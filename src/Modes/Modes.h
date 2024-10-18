#ifndef MODES_H
#define MODES_H

#include "./LED/LED_control.h" // Inclure le fichier d'en-tête de led_control

// Déclaration des modes
enum Mode { MODE_STANDARD, MODE_ECONOMY, MODE_MAINTENANCE };
extern Mode currentMode; // Déclaration de currentMode comme variable externe

// Déclaration des fonctions
void initModes();         // Fonction d'initialisation des modes
void updateModes();       // Fonction de mise à jour des modes
void modeStandard();      // Fonction pour le mode Standard
void modeEconomy();       // Fonction pour le mode Économie
void modeMaintenance();   // Fonction pour le mode Maintenance

#endif // MODES_H