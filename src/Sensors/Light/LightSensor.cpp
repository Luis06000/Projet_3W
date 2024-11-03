#include "LightSensor.h"
#include "Config.h"

LightSensor::LightSensor() : errorCount(0) {
    data.value = 0;
    data.valid = false;
}

bool LightSensor::begin() {
    pinMode(SENSOR_PIN, INPUT);
    return true;
}

const LightData& LightSensor::readData() {
    uint16_t reading = analogRead(SENSOR_PIN);
    
    data.valid = validateReading(reading);
    
    if (data.valid) {
        data.value = reading;
        errorCount = 0;
    } else {
        errorCount++;
    }
    
    return data;
}

bool LightSensor::validateReading(uint16_t value) {
    if (!(params.flags & FLAG_LUMIN)) return false;
    if (value < params.LUMIN_LOW || value > params.LUMIN_HIGH) {
        return false;
    }
    return true;
}
 