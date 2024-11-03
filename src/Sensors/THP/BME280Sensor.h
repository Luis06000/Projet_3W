// #ifndef THP
// #define THP

// #include <Adafruit_BME280.h>
// #include <Wire.h>
// #include <SPI.h>

// class BME280Sensor {
// public:
//     BME280Sensor();
//     bool begin();
//     float Temperature();
//     float Humidity();
//     float Pressure();
//     uint8_t InvalidBMECount();

// private:
//     Adafruit_BME280 bme;
//     uint8_t invalidBMECount;
// };

// #endif








#ifndef BME280SENSOR_H
#define BME280SENSOR_H

#include <Adafruit_BME280.h>
#include <Wire.h>

struct BME280Data {
    float temp;
    float humidity;
    float pressure;
    bool validTemp;
    bool validHum;
    bool validPress;
};

class BME280Sensor {
public:
    BME280Sensor();
    bool begin();
    const BME280Data& readData();
    uint8_t InvalidBMECount() const { return invalidBMECount; }

private:
    Adafruit_BME280 bme;
    BME280Data data;
    uint8_t invalidBMECount;
    bool validateReading(float value, float min, float max);
};

#endif
