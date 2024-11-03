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
#include <SPI.h>
#include <RTClib.h>

class SDCard {
public:
    SDCard(uint8_t SDPin);
    bool begin();
    bool isFunctional();
    void openFile();
    void closeFile();
    void checkFileSize();

    // Fonctions pour écrire des données sur la carte SD
    void printToFile(const char *data);
    void printToFile(int data);
    void printToFile(float data, uint8_t decimalPlaces);

private:
    uint8_t csPin;
    bool functional;
    File logFile;
    char currentFileName[13];
    void generateFileName();

    uint8_t revision;
    DateTime currentDate;

    bool headerWritten; // Indique si l'en-tête a été écrit
    void writeHeader(); // Fonction pour écrire l'en-tête
};

#endif // SDCARD_H






// #ifndef SDCARD_H
// #define SDCARD_H

// #include <SD.h>
// #include <SPI.h>
// #include <RTClib.h>

// struct FileInfo {
//     char fileName[13];
//     uint8_t revision;
//     DateTime date;
//     bool headerWritten;

//     FileInfo() : revision(0), headerWritten(false) {
//         fileName[0] = '\0';
//     }
// };

// class SDCard {
// public:
//     SDCard(uint8_t SDPin);
//     bool begin();
//     bool isFunctional();
//     void openFile();
//     void closeFile();
//     void checkFileSize();

//     // Fonctions pour écrire des données sur la carte SD
//     void printToFile(const char *data);

// private:
//     uint8_t csPin;
//     File logFile;
//     bool functional;
//     FileInfo currentFileInfo;

//     void generateFileName();

//     uint8_t revision;
//     DateTime currentDate;

//     // void writeHeader(); // Fonction pour écrire l'en-tête
// };

// #endif // SDCARD_H


