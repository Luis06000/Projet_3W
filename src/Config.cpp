// #include "Config.h"

// // Définir les adresses de chaque variable dans l'EEPROM
// #define ADDR_LOG_INTERVAL sizeof(unsigned long)
// #define ADDR_FILE_MAX_SIZE (2 * sizeof(unsigned long))
// #define ADDR_LUMIN (3 * sizeof(unsigned long)) // Adresse pour LUMIN
// #define ADDR_TEMP_AIR (4 * sizeof(unsigned long)) // Adresse pour TEMP_AIR
// #define ADDR_HYGR (5 * sizeof(unsigned long)) // Adresse pour HYGR
// #define ADDR_PRESSURE (6 * sizeof(unsigned long)) // Adresse pour PRESSURE
// #define ADDR_LUMIN_LOW (7 * sizeof(unsigned long)) // Adresse pour LUMIN_LOW
// #define ADDR_LUMIN_HIGH (8 * sizeof(unsigned long)) // Adresse pour LUMIN_HIGH
// #define ADDR_MIN_TEMP_AIR (9 * sizeof(unsigned long)) // Adresse pour MIN_TEMP_AIR
// #define ADDR_MAX_TEMP_AIR (10 * sizeof(unsigned long)) // Adresse pour MAX_TEMP_AIR
// #define ADDR_HYGR_MIN (11 * sizeof(unsigned long)) // Adresse pour HYGR_MIN
// #define ADDR_HYGR_MAX (12 * sizeof(unsigned long)) // Adresse pour HYGR_MAX
// #define ADDR_PRESSURE_MIN (13 * sizeof(unsigned long)) // Adresse pour PRESSURE_MIN
// #define ADDR_PRESSURE_MAX (14 * sizeof(unsigned long)) // Adresse pour PRESSURE_MAX
// #define ADDR_TIMEOUT (15 * sizeof(unsigned long)) // Adresse pour TIMEOUT


// // Initialisation des paramètres avec des valeurs par défaut
// unsigned long LOG_INTERVAL = 1;
// unsigned long FILE_MAX_SIZE = 2048;
// unsigned long TIMEOUT = 30;
// bool LUMIN = 1; // Valeur par défaut : capteur activé
// bool TEMP_AIR = 1; // Valeur par défaut : acquisition de la température activée
// bool HYGR = 1; // Valeur par défaut : acquisition de l'humidité activée
// bool PRESSURE = 1; // Valeur par défaut : acquisition de la pression activée
// unsigned long LUMIN_LOW = 255;   // Valeur par défaut
// unsigned long LUMIN_HIGH = 768; // Valeur par défaut
// unsigned long MIN_TEMP_AIR = -10; // Valeur par défaut
// unsigned long MAX_TEMP_AIR = 60; // Valeur par défaut
// unsigned long HYGR_MIN = 0;     // Valeur par défaut
// unsigned long HYGR_MAX = 50;   // Valeur par défaut
// unsigned long PRESSURE_MIN = 850; // Valeur par défaut
// unsigned long PRESSURE_MAX = 1080; // Valeur par défaut

// bool ERREUR = 0;

// // Version du programme
// const String PROGRAM_VERSION = "1.0.0";
// const String BATCH_NUMBER = "BATCH 1"; // Numéro de lot pour le suivi

// // Fonction pour lire les valeurs depuis l'EEPROM au démarrage
// void loadConfigFromEEPROM() {
//     EEPROM.get(ADDR_LOG_INTERVAL, LOG_INTERVAL); // Chargement de LOG_INTERVAL
//     EEPROM.get(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE); // Chargement de FILE_MAX_SIZE
//     EEPROM.get(ADDR_LUMIN, LUMIN); // Chargement de LUMIN
//     EEPROM.get(ADDR_TEMP_AIR, TEMP_AIR); // Chargement de TEMP_AIR
//     EEPROM.get(ADDR_HYGR, HYGR); // Chargement de HYGR
//     EEPROM.get(ADDR_PRESSURE, PRESSURE); // Chargement de PRESSURE
//     EEPROM.get(ADDR_LUMIN_LOW, LUMIN_LOW); // Chargement de LUMIN_LOW
//     EEPROM.get(ADDR_LUMIN_HIGH, LUMIN_HIGH); // Chargement de LUMIN_HIGH
//     EEPROM.get(ADDR_MIN_TEMP_AIR, MIN_TEMP_AIR); // Chargement de MIN_TEMP_AIR
//     EEPROM.get(ADDR_MAX_TEMP_AIR, MAX_TEMP_AIR); // Chargement de MAX_TEMP_AIR
//     EEPROM.get(ADDR_HYGR_MIN, HYGR_MIN); // Chargement de HYGR_MIN
//     EEPROM.get(ADDR_HYGR_MAX, HYGR_MAX); // Chargement de HYGR_MAX
//     EEPROM.get(ADDR_PRESSURE_MIN, PRESSURE_MIN); // Chargement de PRESSURE_MIN
//     EEPROM.get(ADDR_PRESSURE_MAX, PRESSURE_MAX); // Chargement de PRESSURE_MAX
//     EEPROM.get(ADDR_TIMEOUT, TIMEOUT); // Chargement de TIMEOUT
// }

// // Fonction pour sauvegarder une variable dans l'EEPROM
// void saveConfigToEEPROM(const String &paramName) {
//     if (paramName == "LOG_INTERVAL") {
//         EEPROM.put(ADDR_LOG_INTERVAL, LOG_INTERVAL);
//     } else if (paramName == "FILE_MAX_SIZE") {
//         EEPROM.put(ADDR_FILE_MAX_SIZE, FILE_MAX_SIZE);
//     } else if (paramName == "LUMIN") {
//         EEPROM.put(ADDR_LUMIN, LUMIN); // Sauvegarder LUMIN
//     } else if (paramName == "TEMP_AIR") {
//         EEPROM.put(ADDR_TEMP_AIR, TEMP_AIR); // Sauvegarder TEMP_AIR
//     } else if (paramName == "HYGR") {
//         EEPROM.put(ADDR_HYGR, HYGR); // Sauvegarder HYGR
//     } else if (paramName == "PRESSURE") {
//         EEPROM.put(ADDR_PRESSURE, PRESSURE); // Sauvegarder PRESSURE
//     } else if (paramName == "LUMIN_LOW") {
//         EEPROM.put(ADDR_LUMIN_LOW, LUMIN_LOW); // Sauvegarder LUMIN_LOW
//     } else if (paramName == "LUMIN_HIGH") {
//         EEPROM.put(ADDR_LUMIN_HIGH, LUMIN_HIGH); // Sauvegarder LUMIN_HIGH
//     } else if (paramName == "MIN_TEMP_AIR") {
//         EEPROM.put(ADDR_MIN_TEMP_AIR, MIN_TEMP_AIR); // Sauvegarder MIN_TEMP_AIR
//     } else if (paramName == "MAX_TEMP_AIR") {
//         EEPROM.put(ADDR_MAX_TEMP_AIR, MAX_TEMP_AIR); // Sauvegarder MAX_TEMP_AIR
//     } else if (paramName == "HYGR_MIN") {
//         EEPROM.put(ADDR_HYGR_MIN, HYGR_MIN); // Sauvegarder HYGR_MIN
//     } else if (paramName == "HYGR_MAX") {
//         EEPROM.put(ADDR_HYGR_MAX, HYGR_MAX); // Sauvegarder HYGR_MAX
//     } else if (paramName == "PRESSURE_MIN") {
//         EEPROM.put(ADDR_PRESSURE_MIN, PRESSURE_MIN); // Sauvegarder PRESSURE_MIN
//     } else if (paramName == "PRESSURE_MAX") {
//         EEPROM.put(ADDR_PRESSURE_MAX, PRESSURE_MAX); // Sauvegarder PRESSURE_MAX
//     } else if (paramName == "TIMEOUT") {
//         EEPROM.put(ADDR_TIMEOUT, TIMEOUT); // Sauvegarder TIMEOUT
//     }
// }

// // Fonction pour mettre à jour un paramètre et sauvegarder dans l'EEPROM
// void updateConfigParameter(const String &paramName, unsigned long paramValue) {
//     String trimmedParamName = paramName;
//     trimmedParamName.trim(); // Élimine les espaces de début et de fin

//     if (trimmedParamName == "LOG_INTERVAL") {
//         LOG_INTERVAL = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("LOG_INTERVAL: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "FILE_MAX_SIZE") {
//         FILE_MAX_SIZE = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("FILE_MAX_SIZE: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "LUMIN") {
//         LUMIN = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("LUMIN: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "TEMP_AIR") {
//         TEMP_AIR = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("TEMP_AIR: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "HYGR") {
//         HYGR = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("HYGR: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "PRESSURE") {
//         PRESSURE = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("PRESSURE: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "LUMIN_LOW") {
//         LUMIN_LOW = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("LUMIN_LOW: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "LUMIN_HIGH") {
//         LUMIN_HIGH = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("LUMIN_HIGH: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "MIN_TEMP_AIR") {
//         MIN_TEMP_AIR = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("MIN_TEMP_AIR: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "MAX_TEMP_AIR") {
//         MAX_TEMP_AIR = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("MAX_TEMP_AIR: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "HYGR_MIN") {
//         HYGR_MIN = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("HYGR_MIN: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "HYGR_MAX") {
//         HYGR_MAX = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("HYGR_MAX: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "PRESSURE_MIN") {
//         PRESSURE_MIN = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("PRESSURE_MIN: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "PRESSURE_MAX") {
//         PRESSURE_MAX = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("PRESSURE_MAX: "));
//         Serial.println(paramValue);
//     }  else if (trimmedParamName == "TIMEOUT") {
//         TIMEOUT = paramValue;
//         saveConfigToEEPROM(trimmedParamName);
//         Serial.print(F("TIMEOUT: "));
//         Serial.println(paramValue);
//     } else if (trimmedParamName == "RESET") {
//         resetConfig();
//     } else if (trimmedParamName == "VERSION") {
//         displayVersion();
//     } else {
//         Serial.println(F("Paramètre inconnu"));
//     }
// }

// // Fonction pour réinitialiser les paramètres par défaut
// void resetConfig() {
//     LOG_INTERVAL = 1;
//     FILE_MAX_SIZE = 2048;
//     LUMIN = 1;
//     TEMP_AIR = 1;
//     HYGR = 1;
//     PRESSURE = 1;
//     LUMIN_LOW = 255;
//     LUMIN_HIGH = 768;
//     MIN_TEMP_AIR = -10;
//     MAX_TEMP_AIR = 60;
//     HYGR_MIN = 0;
//     HYGR_MAX = 50;
//     PRESSURE_MIN = 850;
//     PRESSURE_MAX = 1080;
//     TIMEOUT = 30;

//     // Sauvegarder les valeurs par défaut dans l'EEPROM
//     saveConfigToEEPROM("LOG_INTERVAL");
//     saveConfigToEEPROM("FILE_MAX_SIZE");
//     saveConfigToEEPROM("LUMIN");
//     saveConfigToEEPROM("TEMP_AIR");
//     saveConfigToEEPROM("HYGR");
//     saveConfigToEEPROM("PRESSURE");
//     saveConfigToEEPROM("LUMIN_LOW");
//     saveConfigToEEPROM("LUMIN_HIGH");
//     saveConfigToEEPROM("MIN_TEMP_AIR");
//     saveConfigToEEPROM("MAX_TEMP_AIR");
//     saveConfigToEEPROM("HYGR_MIN");
//     saveConfigToEEPROM("HYGR_MAX");
//     saveConfigToEEPROM("PRESSURE_MIN");
//     saveConfigToEEPROM("PRESSURE_MAX");
//     saveConfigToEEPROM("TIMEOUT");

//     Serial.println(F("Configuration réinitialisée aux valeurs par défaut."));
// }

// // Fonction pour afficher la version du programme
// void displayVersion() {
//     Serial.print(F("Version du programme: "));
//     Serial.println(PROGRAM_VERSION);
//     Serial.print(F("Numéro de lot: "));
//     Serial.println(BATCH_NUMBER);
// }










#include "Config.h"
#include <EEPROM.h>

const unsigned char EEPROM_FLAG = 0x42;
bool ERREUR = 0;

struct Params params = {
    .LOG_INTERVAL = 1,
    .FILE_MAX_SIZE = 2048,
    .TIMEOUT = 30,
    .LUMIN = 1,
    .LUMIN_LOW = 255,
    .LUMIN_HIGH = 768,
    .TEMP_AIR = 1,
    .MIN_TEMP_AIR = -10,
    .MAX_TEMP_AIR = 60,
    .HYGR = 1,
    .HYGR_MIN = 0,
    .HYGR_MAX = 50,
    .PRESSURE = 1,
    .PRESSURE_MIN = 850,
    .PRESSURE_MAX = 1080,
};

struct Version version = {
    .num = "1.0",
    .lot = "L.01",
};

void Config() {
    byte isConfigured;
    EEPROM.get(0, isConfigured);

    if (isConfigured == EEPROM_FLAG) EEPROM.get(1, params);
    else {
        EEPROM.put(0, EEPROM_FLAG);
        EEPROM.put(1, params);
    }

    Serial.println(F("Paramètres actuels :"));
    Serial.print(F("LOG_INTERVAL="));
    Serial.println(params.LOG_INTERVAL);
    Serial.print(F("FILE_MAX_SIZE="));
    Serial.println(params.FILE_MAX_SIZE);
    Serial.print(F("TIMEOUT="));
    Serial.println(params.TIMEOUT);
    Serial.print(F("LUMIN="));
    Serial.println(params.LUMIN);
    Serial.print(F("LUMIN_LOW="));
    Serial.println(params.LUMIN_LOW);
    Serial.print(F("LUMIN_HIGH="));
    Serial.println(params.LUMIN_HIGH);
    Serial.print(F("TEMP_AIR="));
    Serial.println(params.TEMP_AIR);
    Serial.print(F("MIN_TEMP_AIR="));
    Serial.println(params.MIN_TEMP_AIR);
    Serial.print(F("MAX_TEMP_AIR="));
    Serial.println(params.MAX_TEMP_AIR);
    Serial.print(F("HYGR="));
    Serial.println(params.HYGR);
    Serial.print(F("HYGR_MIN="));
    Serial.println(params.HYGR_MIN);
    Serial.print(F("HYGR_MAX="));
    Serial.println(params.HYGR_MAX);
    Serial.print(F("PRESSURE="));
    Serial.println(params.PRESSURE);
    Serial.print(F("PRESSURE_MIN="));
    Serial.println(params.PRESSURE_MIN);
    Serial.print(F("PRESSURE_MAX="));
    Serial.println(params.PRESSURE_MAX);
}

void updateConfigParameter(const String &paramName, int paramValue) {
    String trimmedParamName = paramName;
    trimmedParamName.trim();
    bool hasChanged=0;

    if (paramName=="LUMIN" && (paramValue == 0 || paramValue == 1)) (params.LUMIN = paramValue) && (hasChanged=1);
    else if (paramName=="LUMIN_LOW" && (paramValue >= 0 && paramValue <= 1023)) (params.LUMIN_LOW = paramValue) && (hasChanged=1);
    else if (paramName=="LUMIN_HIGH" && (paramValue >= 0 && paramValue <= 1023)) (params.LUMIN_HIGH = paramValue) && (hasChanged=1);
    else if (paramName=="TEMP_AIR" && (paramValue == 0 || paramValue == 1)) (params.TEMP_AIR = paramValue) && (hasChanged=1);
    else if (paramName=="MIN_TEMP_AIR" && (paramValue >= -40 && paramValue <= 85)) (params.MIN_TEMP_AIR = paramValue) && (hasChanged=1);
    else if (paramName=="MAX_TEMP_AIR" && (paramValue >= -40 && paramValue <= 85)) (params.MAX_TEMP_AIR = paramValue) && (hasChanged=1);
    else if (paramName=="HYGR" && (paramValue == 0 || paramValue == 1)) (params.HYGR = paramValue) && (hasChanged=1);
    else if (paramName=="HYGR_MIN" && (paramValue >= -40 && paramValue <= 85)) (params.HYGR_MIN = paramValue) && (hasChanged=1);
    else if (paramName=="HYGR_MAX" && (paramValue >= -40 && paramValue <= 85)) (params.HYGR_MAX = paramValue) && (hasChanged=1);
    else if (paramName=="PRESSURE" && (paramValue == 0 || paramValue == 1)) (params.PRESSURE = paramValue) && (hasChanged=1);
    else if (paramName=="PRESSURE_MIN" && (paramValue >= 300 && paramValue <= 1100)) (params.PRESSURE_MIN = paramValue) && (hasChanged=1);
    else if (paramName=="PRESSURE_MAX" && (paramValue >= 300 && paramValue <= 1100)) (params.PRESSURE_MAX = paramValue) && (hasChanged=1);
    else if (paramName=="LOG_INTERVAL") (params.LOG_INTERVAL = paramValue) && (hasChanged=1);
    else if (paramName=="FILE_MAX_SIZE") (params.FILE_MAX_SIZE = paramValue) && (hasChanged=1);
    else if (paramName=="TIMEOUT") (params.TIMEOUT = paramValue) && (hasChanged=1);
    else if (paramName=="RESET") resetConfig();
    else if (paramName=="VERSION") displayVersion();
    else if (paramName == "CLOCK") {
        int newHour = paramValue;
        int newMinute = Serial.parseInt();
        int newSecond = Serial.parseInt();
        if (newHour >= 0 && newHour < 24 && newMinute >= 0 && newMinute < 60 && newSecond >= 0 && newSecond < 60) {
            rtcSensor.adjustClock(newHour, newMinute, newSecond);
            hasChanged = true;
        }
    } else if (paramName == "DATE") {
        int newYear = paramValue;
        int newMonth = Serial.parseInt();
        int newDay = Serial.parseInt();
        if (newYear >= 0 && newMonth > 0 && newMonth <= 12 && newDay > 0 && newDay <= 31) {
            rtcSensor.adjustDate(newYear, newMonth, newDay);
            hasChanged = true;
        }
    }
    else Serial.println(F("Paramètre inconnu ou valeur incorrecte."));
    EEPROM.put(1, params);
    if (hasChanged) Serial.println(F("Nouvelle onfiguration sauvegardée."));
}

void resetConfig() {
    rtcSensor.resetRTC();
    params.LOG_INTERVAL = 1;
    params.FILE_MAX_SIZE = 2048;
    params.TIMEOUT = 30;
    params.LUMIN = 1;
    params.LUMIN_LOW = 255;
    params.LUMIN_HIGH = 768;
    params.TEMP_AIR = 1;
    params.MIN_TEMP_AIR = -10;
    params.MAX_TEMP_AIR = 60;
    params.HYGR = 1;
    params.HYGR_MIN = 0;
    params.HYGR_MAX = 50;
    params.PRESSURE = 1;
    params.PRESSURE_MIN = 850;
    params.PRESSURE_MAX = 1080;

    EEPROM.put(1, params);
    Serial.println(F("Configuration réinitialisée aux valeurs par défaut."));
}


void displayVersion() {
    Serial.print(F("Version: "));
    Serial.println(version.num);
    Serial.print(F("Numéro de lot: "));
    Serial.println(version.lot);
}




