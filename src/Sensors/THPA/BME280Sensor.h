#ifndef THPA
#define THPA

#include <Adafruit_BME280.h>

class BME280Sensor {
public:
    BME280Sensor();  // Constructeur
    bool begin();  // Initialisation du capteur
    void readSensor();  // Lire les données du capteur

private:
    Adafruit_BME280 bme;
    float temperature;
    float humidity;
    float pressure;
    float altitude;
};

#endif