#ifndef THP
#define THP

#include <Adafruit_BME280.h>
#include <Wire.h>
#include <SPI.h>

extern uint8_t invalidBMECount;

class BME280Sensor {
public:
    BME280Sensor();
    bool begin();
    float Temperature();
    float Humidity();
    float Pressure();

private:
    Adafruit_BME280 bme;
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
