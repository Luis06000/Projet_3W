// #include "BME280Sensor.h"


// int32_t rawTemperature;
// int32_t rawPressure;
// int16_t rawHumidity;


// bool beginBME280() {
//     Wire.begin();
//     return true;
// }

// // Fonction pour écrire dans un registre du BME280
// void writeRegister(uint8_t reg, uint8_t value) {
//     Wire.beginTransmission(BME280_ADDRESS);
//     Wire.write(reg);
//     Wire.write(value);
//     Wire.endTransmission();
// }

// // Fonction d'initialisation du capteur BME280
// void initializeBME280() {
//     writeRegister(0xF2, 0x01);  // Configurer l'humidité
//     writeRegister(0xF4, 0x27);  // Configurer la température et la pression
//     writeRegister(0xF5, 0xA0);  // Configurer le temps de standby
// }

// Fonction pour lire les données brutes du capteur BME280
// void readBME280Data() {
//     Wire.beginTransmission(BME280_ADDRESS);
//     Wire.write(0xF7);
//     Wire.endTransmission();
//     Wire.requestFrom(BME280_ADDRESS, 8);

//     rawPressure = ((uint32_t)Wire.read() << 12) | ((uint32_t)Wire.read() << 4) | (Wire.read() >> 4);
//     rawTemperature = ((uint32_t)Wire.read() << 12) | ((uint32_t)Wire.read() << 4) | (Wire.read() >> 4);
//     rawHumidity = (Wire.read() << 8) | Wire.read();

//     // Appliquer les conversions basiques pour obtenir des valeurs réelles
//     float temperature = rawTemperature / 21000.0;   // Conversion température (approximatif)
//     float humidity = rawHumidity / 550.0;           // Ajustement du facteur pour éviter 0
//     float pressure = rawPressure / 280.0;           // Conversion pression (approximatif)

    // // Affichage des valeurs
    // Serial.print("Température: ");
    // Serial.print(temperature, 1);
    // Serial.println(" °C");

    // Serial.print("Humidité: ");
    // Serial.print(humidity, 1);
    // Serial.println(" %");

    // Serial.print("Pression: ");
    // Serial.print(pressure, 1);
    // Serial.println(" hPa");
// }



// void readBME280Data() {
//     Wire.beginTransmission(BME280_ADDRESS);
//     Wire.write(0xF7);  // Point de départ des données
//     Wire.endTransmission();
//     Wire.requestFrom(BME280_ADDRESS, 8);

//     // Lecture des données brutes
//     rawPressure = ((uint32_t)Wire.read() << 12) | ((uint32_t)Wire.read() << 4) | (Wire.read() >> 4);
//     rawTemperature = ((uint32_t)Wire.read() << 12) | ((uint32_t)Wire.read() << 4) | (Wire.read() >> 4);
//     rawHumidity = (Wire.read() << 8) | Wire.read();

//     // Ajustements basiques pour rendre les valeurs plus réalistes
//     float temperature = (rawTemperature / 5120.0) - 40.0;      // Ajustement simplifié pour température
//     float humidity = (rawHumidity / 1024.0) * 100.0;           // Ajustement pour humidité en %
//     float pressure = (rawPressure / 25600.0);                  // Ajustement pour pression en hPa

//     // Affichage des valeurs
//     Serial.print("Température: ");
//     Serial.print(temperature, 1);
//     Serial.println(" °C");

//     Serial.print("Humidité: ");
//     Serial.print(humidity, 1);
//     Serial.println(" %");

//     Serial.print("Pression: ");
//     Serial.print(pressure, 1);
//     Serial.println(" hPa");
// }







#include "BME280Sensor.h"

// Constructeur par défaut
BME280Sensor::BME280Sensor() {}

bool BME280Sensor::begin() {
    return bme.begin(0x76);  // Adresse I2C typique du BME280
}

void BME280Sensor::readSensor() {
    // Vérifier si la lecture de la température est activée
    if (params.TEMP_AIR) {
        temperature = bme.readTemperature();
        Serial.print(F("Température : "));
        Serial.print(temperature, 1);
        Serial.println(F(" °C"));
        
        // Vérifier les limites de température
        if (temperature < params.MIN_TEMP_AIR || temperature > params.MAX_TEMP_AIR) {
            ERREUR = 1;  // Définir ERREUR à 1 si la température est hors limites
        }
    }

    // Vérifier si la lecture de l'humidité est activée
    if (params.HYGR) {
        humidity = bme.readHumidity();
        Serial.print(F("Humidité : "));
        Serial.print(humidity, 1);
        Serial.println(F(" %"));
        
        // Vérifier les limites d'humidité
        if (humidity < params.HYGR_MIN || humidity > params.HYGR_MAX) {
            ERREUR = 1;  // Définir ERREUR à 1 si l'humidité est hors limites
        }
    }

    // Vérifier si la lecture de la pression est activée
    if (params.PRESSURE) {
        pressure = bme.readPressure() * 0.01F;  // Convertir en hPa
        Serial.print(F("Pression : "));
        Serial.print(pressure, 1);
        Serial.println(F(" hPa"));
        
        // Vérifier les limites de pression
        if (pressure < params.PRESSURE_MIN || pressure > params.PRESSURE_MAX) {
            ERREUR = 1;  // Définir ERREUR à 1 si la pression est hors limites
        }
    }
}

