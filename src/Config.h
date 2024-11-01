#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <EEPROM.h>


// Déclaration des variables globales
extern unsigned long LOG_INTERVAL;
extern unsigned long FILE_MAX_SIZE;
extern bool LUMIN;  // Paramètre pour l'acquisition de la luminosité
extern bool TEMP_AIR;  // Paramètre pour l'acquisition de la température
extern bool HYGR;      // Paramètre pour l'acquisition de l'humidité
extern bool PRESSURE;  // Paramètre pour l'acquisition de la pression
extern unsigned long LUMIN_LOW;   // Paramètre pour la luminosité minimale
extern unsigned long LUMIN_HIGH;  // Paramètre pour la luminosité maximale
extern unsigned long MIN_TEMP_AIR; // Paramètre pour la température minimale
extern unsigned long MAX_TEMP_AIR; // Paramètre pour la température maximale
extern unsigned long HYGR_MIN;     // Paramètre pour l'humidité minimale
extern unsigned long HYGR_MAX;     // Paramètre pour l'humidité maximale
extern unsigned long PRESSURE_MIN;  // Paramètre pour la pression minimale
extern unsigned long PRESSURE_MAX;  // Paramètre pour la pression maximale
extern unsigned long TIMEOUT; // Durée avant abandon de l'acquisition (en s)

extern bool ERREUR;  // Paramètre pour l'acquisition de la pression

// Prototypes des fonctions
void loadConfigFromEEPROM();  // Charge les valeurs depuis l'EEPROM
void saveConfigToEEPROM(const String &paramName); // Sauvegarde une variable spécifique dans l'EEPROM
void updateConfigParameter(const String &paramName, unsigned long paramValue); // Met à jour une variable et la sauvegarde dans l'EEPROM
void resetConfig(); // Réinitialise les paramètres par défaut
void displayVersion(); // Affiche la version du programme

#endif

