#ifndef MODES_H
#define MODES_H

#include "./LED/LED_control.h" // Inclure le fichier d'en-tête de led_control
#include <Arduino.h> // Assure-toi d'inclure cette bibliothèque si nécessaire

extern unsigned long lastActivityTime; // Pour suivre le dernier moment d'activité
const unsigned long INACTIVITY_TIMEOUT = 120000; // 2 minutes en millisecondes

// Déclaration des modes
enum Mode { MODE_STANDARD, MODE_ECONOMY, MODE_MAINTENANCE, MODE_CONFIGURATION };
extern Mode currentMode; // Déclaration de currentMode comme variable externe

// Déclaration des fonctions
void initModes();         // Fonction d'initialisation des modes
void updateModes();       // Fonction de mise à jour des modes
void modeStandard();      // Fonction pour le mode Standard
void modeEconomique();       // Fonction pour le mode Économie
void modeMaintenance();   // Fonction pour le mode Maintenance
void modeConfiguration();   // Fonction pour le mode Maintenance

#endif // MODES_H