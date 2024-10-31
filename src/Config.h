// #ifndef CONFIG_H
// #define CONFIG_H

// #include <Arduino.h>

// // Déclaration des variables globales
// extern unsigned long LOG_INTERVALL;
// extern unsigned long LOG_INTERVAL;
// extern unsigned long FILE_MAX_SIZE;

// // Prototypes des fonctions
// void loadConfigFromEEPROM();  // Charge les valeurs depuis l'EEPROM
// void saveConfigToEEPROM(const String &paramName); // Sauvegarde une variable spécifique dans l'EEPROM
// void updateConfigParameter(const String &paramName, unsigned long paramValue); // Met à jour une variable et la sauvegarde dans l'EEPROM

// #endif





// #ifndef CONFIG_H
// #define CONFIG_H

// #include <Arduino.h>

// // Déclaration des variables globales
// extern unsigned long LOG_INTERVALL;
// extern unsigned long LOG_INTERVAL;
// extern unsigned long FILE_MAX_SIZE;

// // Informations de version et de lot
// const String PROGRAM_VERSION = "1.0.0";
// const String BATCH_NUMBER = "2024-01";

// // Prototypes des fonctions
// void loadConfigFromEEPROM();  
// void saveConfigToEEPROM(const String &paramName); 
// void updateConfigParameter(const String &paramName, unsigned long paramValue);
// void resetConfig(); // Remet les paramètres initiaux
// void printVersion(); // Affiche la version du programme et le numéro de lot

// #endif



#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Déclaration des variables globales
extern unsigned long LOG_INTERVALL;
extern unsigned long LOG_INTERVAL;
extern unsigned long FILE_MAX_SIZE;

// Prototypes des fonctions
void loadConfigFromEEPROM();  // Charge les valeurs depuis l'EEPROM
void saveConfigToEEPROM(const String &paramName); // Sauvegarde une variable spécifique dans l'EEPROM
void updateConfigParameter(const String &paramName, unsigned long paramValue); // Met à jour une variable et la sauvegarde dans l'EEPROM
void resetConfig(); // Réinitialise les paramètres par défaut
void displayVersion(); // Affiche la version du programme

#endif