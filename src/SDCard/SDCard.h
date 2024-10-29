// #ifndef SDCARD_H
// #define SDCARD_H
// #include <SD.h>
// #include <RTClib.h>
// #include <SPI.h>
// // Définition des constantes et variables globales
// #define CHIP_SELECT_PIN 4 // Pin CS pour le module SD
// #define MAX_FILE_SIZE 4096 // Taille max par défaut (4 Ko)
// extern RTC_DS3231 rtc; // Module RTC
// extern File logFile;
// extern char filename[13]; // Format: "YYMMDD_X.LOG"
// extern int currentRevision; // Révision actuelle du fichier
// // Déclaration des fonctions
// void generateFilename(int revision);
// void logData();
// void resetLogFile();
// void checkFileSize();
// void setupSDCard();
// bool isSDCardFull(); // Nouvelle fonction pour vérifier si la carte SD est pleine
// #endif // SDCARD_H



#ifndef SDCARD_H
#define SDCARD_H

#include <SD.h>
#include <RTClib.h>
#include <SPI.h>

// Définition des constantes et variables globales
#define CHIP_SELECT_PIN 4 // Pin CS pour le module SD
#define MAX_FILE_SIZE 4096 // Taille max par défaut (4 Ko)

extern RTC_DS3231 rtc; // Module RTC
extern File logFile;
extern char filename[13]; // Format: "YYMMDD_X.LOG"
extern int currentRevision; // Révision actuelle du fichier

// Déclaration des fonctions
void generateFilename(int revision);
void logData();
void resetLogFile();
void checkFileSize();
void setupSDCard();
bool isSDCardFull(); // Nouvelle fonction pour vérifier si la carte SD est pleine

#endif // SDCARD_H
