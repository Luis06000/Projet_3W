// #include "Config.h"
// #include "BME280Sensor.h"

// // Constructeur par défaut
// BME280Sensor::BME280Sensor() : invalidBMECount(0) {}

// bool BME280Sensor::begin() {
//     return bme.begin(0x76);  // Adresse I2C typique du BME280
// }

// float BME280Sensor::Temperature() {
//     float temperature = bme.readTemperature();

//     if (isnan(temperature)) invalidBMECount++;
//     else {
//         invalidBMECount = 0;
//         if (temperature < params.MIN_TEMP_AIR || temperature > params.MAX_TEMP_AIR) {
//             ERREUR = 1;
//         }
//     }
//     return temperature;
// }

// float BME280Sensor::Humidity() {
//     float humidity = bme.readHumidity();

//     if (isnan(humidity)) invalidBMECount++;
//     else {
//         invalidBMECount = 0;
//         if (humidity < params.HYGR_MIN || humidity > params.HYGR_MAX) {
//             ERREUR = 1;
//         }
//     }
//     return humidity;
// }

// float BME280Sensor::Pressure() {
//     float pressure = bme.readPressure() * 0.01F;

//     if (isnan(pressure)) invalidBMECount++;
//     else {
//         invalidBMECount = 0;
//         if (pressure < params.PRESSURE_MIN || pressure > params.PRESSURE_MAX) {
//             ERREUR = 1;
//         }
//     }
//     return pressure;
// }

// uint8_t BME280Sensor::InvalidBMECount() {
//     return invalidBMECount;
// }







#include "BME280Sensor.h"
#include "Config.h"

BME280Sensor::BME280Sensor() : invalidBMECount(0) {
    data.temp = 0;
    data.humidity = 0;
    data.pressure = 0;
    data.validTemp = false;
    data.validHum = false;
    data.validPress = false;
}

bool BME280Sensor::begin() {
    return bme.begin(0x76);
}

const BME280Data& BME280Sensor::readData() {
    float temp = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() * 0.01F;
    
    bool allValid = true;
    
    // Validation de la température
    data.validTemp = !isnan(temp) && temp >= params.MIN_TEMP_AIR && temp <= params.MAX_TEMP_AIR;
    if (data.validTemp) {
        data.temp = temp;
    } else {
        allValid = false;
    }
    
    // Validation de l'humidité
    data.validHum = !isnan(humidity) && humidity >= params.HYGR_MIN && humidity <= params.HYGR_MAX;
    if (data.validHum) {
        data.humidity = humidity;
    } else {
        allValid = false;
    }
    
    // Validation de la pression
    data.validPress = !isnan(pressure) && pressure >= params.PRESSURE_MIN && pressure <= params.PRESSURE_MAX;
    if (data.validPress) {
        data.pressure = pressure;
    } else {
        allValid = false;
    }
    
    // Mise à jour du compteur d'erreurs
    if (!allValid) {
        invalidBMECount++;
    } else {
        invalidBMECount = 0;
    }
    
    return data;
}

bool BME280Sensor::validateReading(float value, float min, float max) {
    if (isnan(value)) return false;
    if (value < min || value > max) {
        ERREUR = 1;
        return false;
    }
    return true;
}
