#ifndef THP
#define THP

#include "Config.h"
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <SPI.h>

class BME280Sensor {
public:
    BME280Sensor();  // Constructeur
    bool begin();  // Initialisation du capteur
    void readSensor();  // Lire les données du capteur

private:
    Adafruit_BME280 bme;
    float temperature{0.0};
    float humidity{0.0};
    float pressure{0.0};
};

#endif








// #ifndef THP
// #define THP

// #include "Config.h"
// #include <Wire.h>
// #include <SPI.h>

// #define BME280_ADDRESS 0x76

// bool beginBME280();
// void initializeBME280();
// void readBME280Data();
// void readCalibrationData();

// #endif
