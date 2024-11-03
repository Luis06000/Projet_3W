#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>

struct LightData {
    uint16_t value;
    bool valid;
};

class LightSensor {
public:
    LightSensor();
    bool begin();
    const LightData& readData();
    uint8_t InvalidLightCount() const { return errorCount; }

private:
    static const uint8_t SENSOR_PIN = A0;
    LightData data;
    uint8_t errorCount;
    bool validateReading(uint16_t value);
};

#endif