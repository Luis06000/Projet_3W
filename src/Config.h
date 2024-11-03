#ifndef CONFIG_H
#define CONFIG_H

#include "RTC/RTC.h"
#include <Arduino.h>

extern RTC rtc;

struct Params {
    uint8_t LOG_INTERVAL;
    uint16_t FILE_MAX_SIZE;
    uint8_t TIMEOUT;
    uint8_t flags;
    uint16_t LUMIN_LOW;
    uint16_t LUMIN_HIGH;
    int8_t MIN_TEMP_AIR;
    int8_t MAX_TEMP_AIR;
    int8_t HYGR_MIN;
    int8_t HYGR_MAX;
    uint16_t PRESSURE_MIN;
    uint16_t PRESSURE_MAX;
};

struct Version {
    const char* num;
    const char* lot;
};

extern struct Params params;
extern bool ERREUR;

#define FLAG_LUMIN    0x01
#define FLAG_TEMP_AIR 0x02
#define FLAG_HYGR     0x04
#define FLAG_PRESSURE 0x08

void Config();
void updateConfigParameter(const String &paramName, int paramValue);
void resetConfig();
void displayVersion();

#endif
