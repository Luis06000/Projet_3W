// // Inclusion des bibliothèques nécessaires
// #include <SD.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <RTClib.h>
// #include <Adafruit_Sensor.h>

// // Définitions des constantes
// #define LOG_INTERVAL 600000 // Intervalle de 10 minutes (en millisecondes)
// #define FILE_MAX_SIZE 2048  // Taille maximale du fichier de log en octets
// #define TIMEOUT 30000       // Timeout capteurs (30s)

// // Variables globales
// RTC_DS1307 rtc;
// File logFile;

// // Structures pour les données des capteurs
// struct SensorData {
//     float pressure;
//     float temperature;
//     float humidity;
//     float gpsLat;
//     float gpsLong;
//     float luminosity;
//     bool error;
// };

// // Fonctions de configuration
// void setupSensors();
// void setupSDCard();
// void setupRTC();
// void setupLED();

// // Fonctions principales du programme
// void logSensorData();
// void switchMode(int mode);
// void handleError(int errorCode);

// // Fonctions d'acquisition des capteurs
// SensorData readSensors();
// void logDataToSD(SensorData data);

// // Modes de fonctionnement
// void modeStandard();
// void modeConfiguration();
// void modeMaintenance();
// void modeEconomy();

// void setup() {
//     // Initialisation des composants
//     setupLED();
//     setupRTC();
//     setupSDCard();
//     setupSensors();

//     // Lancement en mode standard par défaut
//     modeStandard();
// }

// void loop() {
//     // Gestion des différents modes en fonction des interactions utilisateur
//     int mode = checkUserInput();
//     switchMode(mode);

//     // Si en mode standard, acquisition et enregistrement des données
//     if (mode == 0) {
//         logSensorData();
//     }
// }

// // Fonction de configuration des capteurs
// void setupSensors() {
//     // Initialisation des capteurs : pression, température, humidité, GPS, luminosité
// }

// // Fonction de configuration de la carte SD
// void setupSDCard() {
//     if (!SD.begin(10)) {
//         handleError(1); // Erreur d'accès à la carte SD
//     }
// }

// // Fonction de configuration de l'horloge RTC
// void setupRTC() {
//     if (!rtc.begin()) {
//         handleError(2); // Erreur d'accès à l'horloge
//     }
// }

// // Fonction de gestion des erreurs
// void handleError(int errorCode) {
//     // Clignotement des LEDs pour indiquer l'erreur spécifique
// }

// // Fonction d'acquisition et d'enregistrement des données des capteurs
// void logSensorData() {
//     SensorData data = readSensors();
//     logDataToSD(data);
// }

// // Fonction de lecture des capteurs
// SensorData readSensors() {
//     SensorData data;
//     // Lecture des données de chaque capteur
//     data.pressure = readPressureSensor();
//     data.temperature = readTemperatureSensor();
//     data.humidity = readHumiditySensor();
//     data.gpsLat = readGPSSensorLat();
//     data.gpsLong = readGPSSensorLong();
//     data.luminosity = readLuminositySensor();
//     data.error = false; // Aucun problème détecté
//     return data;
// }

// // Fonction d'enregistrement des données sur la carte SD
// void logDataToSD(SensorData data) {
//     logFile = SD.open("data.log", FILE_WRITE);
//     if (logFile) {
//         logFile.print(rtc.now().timestamp());
//         logFile.print(", ");
//         logFile.print(data.pressure);
//         logFile.print(", ");
//         logFile.print(data.temperature);
//         logFile.print(", ");
//         logFile.print(data.humidity);
//         logFile.print(", ");
//         logFile.print(data.gpsLat);
//         logFile.print(", ");
//         logFile.print(data.gpsLong);
//         logFile.print(", ");
//         logFile.println(data.luminosity);
//         logFile.close();
//     } else {
//         handleError(3); // Erreur d'écriture sur la carte SD
//     }
// }

// // Fonctions des différents modes de fonctionnement
// void modeStandard() {
//     // Mode par défaut, acquisition des données
// }

// void modeConfiguration() {
//     // Configuration des paramètres via interface série
// }

// void modeMaintenance() {
//     // Affichage des données en direct, changement de la carte SD en sécurité
// }

// void modeEconomy() {
//     // Réduction de la fréquence des acquisitions pour économiser l'énergie
// }

// int checkUserInput() {
//     // Lecture des boutons poussoirs et renvoi du mode choisi
//     return 0; // Par défaut, mode standard
// }



// #include "ChainableLED.h"

// #define NUM_LEDS  5

// ChainableLED leds(7, 8, NUM_LEDS); // Initialize directly

// float hue = 0.0;
// boolean up = true;

// void setup() {
//   // No need for leds.init();
// }

// void loop() {
//   for (byte i = 0; i < NUM_LEDS; i++) {
//     leds.setColorHSB(i, hue, 1.0, 0.5); // Set color using HSB
//   }

//   delay(50);

//   if (up) {
//     hue += 0.025;
//   } else {
//     hue -= 0.025;
//   }

//   if (hue >= 1.0 && up) {
//     up = false;
//   } else if (hue <= 0.0 && !up) {
//     up = true;
//   }
// }