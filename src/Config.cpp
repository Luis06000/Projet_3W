// #include <EEPROM.h>
// #include <SoftwareSerial.h>
// #include "Config.h"

// // Définir les adresses de chaque variable dans l'EEPROM
// #define ADDR_LOG_INTERVALL 0
// #define ADDR_LOG_INTERVAL sizeof(unsigned long)
// #define ADDR_FILE_MAX_SIZE (2 * sizeof(unsigned long))


// unsigned long LOG_INTERVALL = 1;
// unsigned long LOG_INTERVAL = LOG_INTERVALL * 60000;
// unsigned long FILE_MAX_SIZE = 4096;



// // Fonction pour lire les valeurs depuis l'EEPROM au démarrage
// void loadConfigFromEEPROM() {
//     EEPROM.get(ADDR_LOG_INTERVALL, LOG_INTERVALL);
//     EEPROM.get(ADDR_LOG_INTERVAL, LOG_INTERVAL);
//     EEPROM.get(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE);
// }

// // Fonction pour sauvegarder une variable dans l'EEPROM
// void saveConfigToEEPROM(const String &paramName) {
//     if (paramName == "LOG_INTERVALL") {
//         EEPROM.put(ADDR_LOG_INTERVALL, LOG_INTERVALL);
//         LOG_INTERVAL = LOG_INTERVALL * 60000; // Recalcul de LOG_INTERVAL
//         EEPROM.put(ADDR_LOG_INTERVAL, LOG_INTERVAL);
//     } else if (paramName == "FILE_MAX_SIZE") {
//         EEPROM.put(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE);
//     }
// }

// // Fonction pour mettre à jour un paramètre et sauvegarder dans l'EEPROM
// void updateConfigParameter(const String &paramName, unsigned long paramValue) {
//     if (paramName == "LOG_INTERVALL") {
//         LOG_INTERVALL = paramValue;
//         saveConfigToEEPROM(paramName);
//     } else if (paramName == "FILE_MAX_SIZE") {
//         FILE_MAX_SIZE = paramValue;
//         saveConfigToEEPROM(paramName);
//     } else {
//         Serial.println("Paramètre inconnu.");
//     }
// }







#include <EEPROM.h>
#include "Config.h"

// Définir les adresses de chaque variable dans l'EEPROM
#define ADDR_LOG_INTERVALL 0
#define ADDR_LOG_INTERVAL sizeof(unsigned long)
#define ADDR_FILE_MAX_SIZE (2 * sizeof(unsigned long))

// Initialisation des paramètres avec des valeurs par défaut
unsigned long LOG_INTERVALL = 1;
unsigned long LOG_INTERVAL = LOG_INTERVALL * 60000;
unsigned long FILE_MAX_SIZE = 4096;

// Fonction pour lire les valeurs depuis l'EEPROM au démarrage
void loadConfigFromEEPROM() {
    EEPROM.get(ADDR_LOG_INTERVALL, LOG_INTERVALL);
    EEPROM.get(ADDR_LOG_INTERVAL, LOG_INTERVAL);
    EEPROM.get(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE);
}

// Fonction pour sauvegarder une variable dans l'EEPROM
void saveConfigToEEPROM(const String &paramName) {
    if (paramName == "LOG_INTERVALL") {
        EEPROM.put(ADDR_LOG_INTERVALL, LOG_INTERVALL);
        LOG_INTERVAL = LOG_INTERVALL * 60000; // Recalcul de LOG_INTERVAL
        EEPROM.put(ADDR_LOG_INTERVAL, LOG_INTERVAL);
    } else if (paramName == "FILE_MAX_SIZE") {
        EEPROM.put(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE);
    }
}

// Fonction pour mettre à jour un paramètre et sauvegarder dans l'EEPROM
void updateConfigParameter(const String &paramName, unsigned long paramValue) {
    String trimmedParamName = paramName;
    trimmedParamName.trim(); // Élimine les espaces de début et de fin

    if (trimmedParamName == "LOG_INTERVALL") {
        LOG_INTERVALL = paramValue;
        saveConfigToEEPROM(trimmedParamName);
        Serial.print(F("LOG_INTERVALL mis à jour avec la valeur : "));
        Serial.println(paramValue);
    } else if (trimmedParamName == "FILE_MAX_SIZE") {
        FILE_MAX_SIZE = paramValue;
        saveConfigToEEPROM(trimmedParamName);
        Serial.print(F("FILE_MAX_SIZE mis à jour avec la valeur : "));
        Serial.println(paramValue);
    } else {
        Serial.println(F("Paramètre inconnu."));
    }
}

