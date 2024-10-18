// #include <SoftwareSerial.h>
// #include "AsyncDelay.h"
// #include "Wire.h"
// #include <SPI.h>
// #include <TinyGPS++.h>


// #include <Adafruit_Sensor.h>
// #include <Adafruit_BME280.h>

// // Adresse I2C du capteur BME280
// #define SEALEVELPRESSURE_HPA (1013.25)

// Adafruit_BME280 bme;  // Créer une instance du capteur BME280

// void setup() {
//   Serial.begin(9600);
//   Serial.println(F("Initialisation du capteur BME280..."));

//   if (!bme.begin(0x76)) {  // Adresse I2C typique du BME280
//     Serial.println("Erreur de communication avec le capteur BME280.");
//     while (1);
//   }

//   Serial.println(F("Capteur BME280 initialisé avec succès !"));
// }

// void loop() {
//   // Lire les valeurs du capteur BME280
//   float temperature = bme.readTemperature();
//   float humidity = bme.readHumidity();
//   float pressure = bme.readPressure() / 100.0F;  // Convertir la pression en hPa
//   float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);  // Calculer l'altitude approximative

//   // Afficher les valeurs dans le Moniteur Série
//   Serial.print("Température : ");
//   Serial.print(temperature);
//   Serial.println(" °C");

//   Serial.print("Humidité : ");
//   Serial.print(humidity);
//   Serial.println(" %");

//   Serial.print("Pression : ");
//   Serial.print(pressure);
//   Serial.println(" hPa");

//   Serial.print("Altitude approximative : ");
//   Serial.print(altitude);
//   Serial.println(" m");

//   Serial.println();
//   delay(2000);  // Attendre 2 secondes avant de refaire une lecture
// }