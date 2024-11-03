// #include "SDCard.h"
// // Initialisation des variables globales
// RTC_DS3231 rtc;
// File logFile;
// char filename[13];
// int currentRevision = 0;
// void setupSDCard() {
//     Serial.begin(9600);
    
//     // Initialisation de la carte SD
//     if (!SD.begin(CHIP_SELECT_PIN)) {
//         Serial.println("Erreur d'initialisation de la carte SD.");
//         return; // Sortie si la carte SD n'est pas initialisée
//     }
//     Serial.println("Carte SD initialisée avec succès.");
    
//     // Initialisation du RTC
//     if (!rtc.begin()) {
//         Serial.println("Erreur de communication avec le RTC.");
//         return; // Sortie si le RTC n'est pas initialisé
//     }
//     // Vérification du RTC
//     if (rtc.lostPower()) {
//         Serial.println("RTC a perdu l'alimentation, réglage à l'heure actuelle.");
//         // Ici vous pouvez définir l'heure, par exemple :
//         // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//     }
//     resetLogFile(); // Réinitialiser le fichier de journal
// }
// void logData() {
//     // Vérifier si la carte SD est pleine
//     if (isSDCardFull()) {
//         Serial.println("La carte SD est pleine. Veuillez libérer de l'espace.");
//         return;
//     }
//     // Générer le nom du fichier
//     generateFilename(currentRevision); // On écrit toujours dans le fichier correspondant à la révision actuelle
//     // Ouvrir le fichier pour écrire
//     logFile = SD.open(filename, FILE_WRITE);
//     if (logFile) {
//         // Vérifiez la taille du fichier avant d'écrire
//         checkFileSize();
//         // Récupère l'heure actuelle
//         DateTime now = rtc.now();
        
//         // Écrire l'heure et une donnée fictive
//         logFile.print(now.timestamp());
//         logFile.print(","); // Séparateur
//         logFile.print(analogRead(A0)); // Exemple de lecture d'un capteur analogique
//         logFile.println();
        
//         logFile.close();
//         Serial.println("Données enregistrées sur la carte SD.");
//     } else {
//         Serial.println("Erreur d'ouverture du fichier pour l'enregistrement.");
//     }
// }
// void generateFilename(int revision) {
//     DateTime now = rtc.now();
//     snprintf(filename, sizeof(filename), "%02d%02d%02d_%d.LOG", now.year() % 100, now.month(), now.day(), revision);
// }
// void resetLogFile() {
//     // Vérifie si le fichier existe déjà et le supprime
//     if (SD.exists(filename)) {
//         SD.remove(filename);
//         Serial.println("Fichier existant supprimé.");
//     }
// }
// void checkFileSize() {
//     // Vérifier la taille du fichier
//     if (logFile.size() >= MAX_FILE_SIZE) {
//         logFile.close(); // Fermer le fichier
//         currentRevision++; // Augmenter la révision
//         // Vérifiez si le nouveau fichier existe déjà, sinon, le créer
//         generateFilename(currentRevision);
//         if (SD.exists(filename)) {
//             // Si le fichier existe déjà, supprimer l'ancien
//             SD.remove(filename);
//             Serial.println("Ancien fichier supprimé.");
//         }
//         Serial.println("Création d'un nouveau fichier pour la révision suivante.");
//     }
// }
// bool isSDCardFull() {
//     File tempFile = SD.open("temp.txt", FILE_WRITE);
//     if (!tempFile) {
//         // Si l'ouverture échoue, il est possible que la carte soit pleine
//         return true;
//     }
//     tempFile.close();
//     SD.remove("temp.txt"); // Supprimez le fichier temporaire après le test
//     return false;
// }






// #include "SDCard.h"

// // Initialisation des variables globales
// RTC_DS3231 rtc;
// File logFile;
// char filename[13];
// int currentRevision = 0;

// void setupSDCard() {
//     Serial.begin(9600);
    
//     // Initialisation de la carte SD
//     if (!SD.begin(CHIP_SELECT_PIN)) {
//         Serial.println("Erreur d'initialisation de la carte SD.");
//         return; // Sortie si la carte SD n'est pas initialisée
//     }
//     Serial.println("Carte SD initialisée avec succès.");
    
//     // Initialisation du RTC
//     if (!rtc.begin()) {
//         Serial.println("Erreur de communication avec le RTC.");
//         return; // Sortie si le RTC n'est pas initialisé
//     }
    
//     // Vérification du RTC
//     if (rtc.lostPower()) {
//         Serial.println("RTC a perdu l'alimentation, réglage à l'heure actuelle.");
//         // Ici vous pouvez définir l'heure, par exemple :
//         // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//     }
//     resetLogFile(); // Réinitialiser le fichier de journal
// }

// void logData() {
//     // Vérifier si la carte SD est pleine
//     if (isSDCardFull()) {
//         Serial.println("La carte SD est pleine. Veuillez libérer de l'espace.");
//         return;
//     }
    
//     // Générer le nom du fichier
//     generateFilename(currentRevision); // On écrit toujours dans le fichier correspondant à la révision actuelle
    
//     // Ouvrir le fichier pour écrire
//     logFile = SD.open(filename, FILE_WRITE);
//     if (logFile) {
//         // Vérifiez la taille du fichier avant d'écrire
//         checkFileSize();
        
//         // Récupère l'heure actuelle
//         DateTime now = rtc.now();
        
//         // Écrire l'heure et une donnée fictive
//         logFile.print(now.timestamp());
//         logFile.print(","); // Séparateur
//         logFile.print(analogRead(A0)); // Exemple de lecture d'un capteur analogique
//         logFile.println();
        
//         logFile.close();
//         Serial.println("Données enregistrées sur la carte SD.");
//     } else {
//         Serial.println("Erreur d'ouverture du fichier pour l'enregistrement.");
//     }
// }

// void generateFilename(int revision) {
//     DateTime now = rtc.now();
//     snprintf(filename, sizeof(filename), "%02d%02d%02d_%d.LOG", now.year() % 100, now.month(), now.day(), revision);
// }

// void resetLogFile() {
//     // Vérifie si le fichier existe déjà et le supprime
//     if (SD.exists(filename)) {
//         SD.remove(filename);
//         Serial.println("Fichier existant supprimé.");
//     }
// }

// void checkFileSize() {
//     // Vérifier la taille du fichier
//     if (logFile.size() >= MAX_FILE_SIZE) {
//         logFile.close(); // Fermer le fichier
//         currentRevision++; // Augmenter la révision
        
//         // Vérifiez si le nouveau fichier existe déjà, sinon, le créer
//         generateFilename(currentRevision);
//         if (SD.exists(filename)) {
//             // Si le fichier existe déjà, supprimer l'ancien
//             SD.remove(filename);
//             Serial.println("Ancien fichier supprimé.");
//         }
//         Serial.println("Création d'un nouveau fichier pour la révision suivante.");
//     }
// }

// bool isSDCardFull() {
//     File tempFile = SD.open("temp.txt", FILE_WRITE);
//     if (!tempFile) {
//         // Si l'ouverture échoue, il est possible que la carte soit pleine
//         return true;
//     }
//     tempFile.close();
//     SD.remove("temp.txt"); // Supprimez le fichier temporaire après le test
//     return false;
// }






#include "SDCard.h"
#include "RTC/RTC.h"
#include "Config.h"

RTC_DS1307 rtc;

SDCard::SDCard(uint8_t SDPin) : csPin(SDPin), functional(false), revision(0), headerWritten(false) {}

bool SDCard::begin() {
    functional = SD.begin(csPin);
    if (functional) {
        currentDate = rtc.now();
        generateFileName();
    } else {
        Serial.println("Échec de l'initialisation de la carte SD");
    }
    return functional;
}

bool SDCard::isFunctional() {
    return functional;
}

void SDCard::generateFileName() {
    DateTime now = rtc.now();

    // Vérifie si la date a changé
    if (now.day() != currentDate.day() || now.month() != currentDate.month() || now.year() != currentDate.year()) {
        revision = 0;
        currentDate = now;
        headerWritten = false;
    }

    snprintf(currentFileName, sizeof(currentFileName), "%02d%02d%02d_%d.txt",
             now.year() % 100, now.month(), now.day(), revision);
}

void SDCard::openFile() {
    logFile = SD.open(currentFileName, FILE_WRITE);
    if (!logFile) {
        functional = false;
    } else {
        if (!headerWritten) {
            writeHeader();
            headerWritten = true;
        }
    }
}

void SDCard::writeHeader() {
    if (functional && logFile) {
        logFile.println(F("DateHeure,Lumiere,Temperature,Pression,Humidite,Latitude,Longitude"));
        logFile.flush();
    }
}

void SDCard::closeFile() {
    if (logFile) {
        logFile.close();
    }
}

void SDCard::checkFileSize() {
    if (logFile.size() >= params.FILE_MAX_SIZE) {
        logFile.close();

        // Incrémente la révision et génère un nouveau nom de fichier
        revision++;
        generateFileName();
        headerWritten = false; // Réinitialise le drapeau pour le nouvel en-tête
    }
}

void SDCard::printToFile(const char *data) {
    if (functional && logFile) {
        logFile.print(data);
    }
}

void SDCard::printToFile(int data) {
    if (functional && logFile) {
        logFile.print(data);
    }
}

void SDCard::printToFile(float data, uint8_t decimalPlaces) {
    if (functional && logFile) {
        logFile.print(data, decimalPlaces);
    }
}






// #include "SDCard.h"
// #include "RTC/RTC.h"
// #include "Config.h"

// RTC_DS1307 rtc;

// SDCard::SDCard(uint8_t SDPin)
//     : csPin(SDPin), functional(false), revision(0), headerWritten(false) {}

// bool SDCard::begin() {
//     functional = SD.begin(csPin);
//     if (functional) {
//         currentDate = rtc.now();
//         generateFileName();
//     }
//     return functional;
// }

// void SDCard::generateFileName() {
//     const DateTime& now = rtc.now(); // Passage par référence constante

//     // Vérifie si la date a changé
//     if (now.day() != currentDate.day() || now.month() != currentDate.month() || now.year() != currentDate.year()) {
//         revision = 0;
//         currentDate = now;
//         headerWritten = false;
//     }

//     snprintf(currentFileName, sizeof(currentFileName), "%02u%02u%02u_%u.txt",
//              now.year() % 100, now.month(), now.day(), revision);
// }

// void SDCard::openFile() {
//     logFile = SD.open(currentFileName, FILE_WRITE);
//     functional = logFile ? true : false;
//     headerWritten = logFile ? headerWritten : false;
// }

// // void SDCard::writeHeader() {
// //     if (functional && logFile) {
// //         logFile.println("DateHeure,Lumiere,Temperature,Pression,Humidite,Latitude,Longitude");
// //         logFile.flush();
// //     }
// // }

// void SDCard::closeFile() {
//     if (logFile) {
//         logFile.close();
//     }
// }

// void SDCard::checkFileSize() {
//     if (logFile.size() >= params.FILE_MAX_SIZE) {
//         closeFile();
//         revision++;
//         generateFileName();
//         headerWritten = false;
//     }
// }

// void SDCard::printToFile(const char *data) {
//     if (functional && logFile) {
//         logFile.print(data);
//     }
// }

// bool SDCard::isFunctional() {
//     return functional;
// }









// #include "SDCard.h"
// #include "RTC/RTC.h"
// #include "Config.h"

// RTC_DS1307 rtc;

// SDCard::SDCard(uint8_t SDPin)
//     : csPin(SDPin), functional(false), revision(0) {}

// bool SDCard::begin() {
//     functional = SD.begin(csPin);
//     if (functional) {
//         currentFileInfo.date = rtc.now();
//         generateFileName();
//     }
//     return functional;
// }

// void SDCard::generateFileName() {
//     const DateTime& now = rtc.now(); // Passage par référence constante

//     // Vérifie si la date a changé
//     if (now.day() != currentFileInfo.date.day() || now.month() != currentFileInfo.date.month() || now.year() != currentFileInfo.date.year()) {
//         currentFileInfo.revision = 0;
//         currentFileInfo.date = now;
//         currentFileInfo.headerWritten = false;
//     }

//     snprintf(currentFileInfo.fileName, sizeof(currentFileInfo.fileName), "%02u%02u%02u_%u.txt",
//              now.year() % 100, now.month(), now.day(), currentFileInfo.revision);
// }

// void SDCard::openFile() {
//     logFile = SD.open(currentFileInfo.fileName, FILE_WRITE);
//     functional = logFile ? true : false;
//     currentFileInfo.headerWritten = logFile ? currentFileInfo.headerWritten : false;
// }

// // void SDCard::writeHeader() {
// //     if (functional && logFile) {
// //         logFile.println("DateHeure,Lumiere,Temperature,Pression,Humidite,Latitude,Longitude");
// //         logFile.flush();
// //     }
// // }

// void SDCard::closeFile() {
//     if (logFile) {
//         logFile.close();
//     }
// }

// void SDCard::checkFileSize() {
//     if (logFile.size() >= params.FILE_MAX_SIZE) {
//         closeFile();
//         currentFileInfo.revision++;
//         generateFileName();
//         currentFileInfo.headerWritten = false;
//     }
// }

// void SDCard::printToFile(const char *data) {
//     if (functional && logFile) {
//         logFile.print(data);
//     }
// }

// bool SDCard::isFunctional() {
//     return functional;
// }

