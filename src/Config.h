#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Déclaration des variables globales
extern unsigned long LOG_INTERVALL;
extern unsigned long LOG_INTERVAL;
extern unsigned long FILE_MAX_SIZE;
// extern unsigned bool RESET;
// extern unsigned bool VERSION;

// Prototypes des fonctions
void loadConfigFromEEPROM();  // Charge les valeurs depuis l'EEPROM
void saveConfigToEEPROM(const String &paramName); // Sauvegarde une variable spécifique dans l'EEPROM
void updateConfigParameter(const String &paramName, unsigned long paramValue); // Met à jour une variable et la sauvegarde dans l'EEPROM

#endif
