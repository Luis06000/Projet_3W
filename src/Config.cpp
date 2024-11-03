#include "Config.h"
#include <EEPROM.h>

const char MSG_RESET[] PROGMEM = "Configuration réinitialisée";

const unsigned char EEPROM_FLAG = 0x42;
bool ERREUR = 0;

struct Params params = {
    .LOG_INTERVAL = 1,
    .FILE_MAX_SIZE = 2048,
    .TIMEOUT = 30,
    .flags = FLAG_LUMIN | FLAG_TEMP_AIR | FLAG_HYGR | FLAG_PRESSURE,
    .LUMIN_LOW = 255,
    .LUMIN_HIGH = 768,
    .MIN_TEMP_AIR = -10,
    .MAX_TEMP_AIR = 60,
    .HYGR_MIN = 0,
    .HYGR_MAX = 50,
    .PRESSURE_MIN = 850,
    .PRESSURE_MAX = 1080
};

struct Version version = {
    .num = "1.0",
    .lot = "L.01",
};

void Config() {
    byte isConfigured;
    EEPROM.get(0, isConfigured);

    if (isConfigured == EEPROM_FLAG) EEPROM.get(1, params);
    else {
        EEPROM.put(0, EEPROM_FLAG);
        EEPROM.put(1, params);
    }
}

void updateConfigParameter(const String &paramName, int paramValue) {
    bool hasChanged=0;

    if (paramName == "LUMIN") {
        if (paramValue == 0) params.flags &= ~FLAG_LUMIN;
        else if (paramValue == 1) params.flags |= FLAG_LUMIN;
        hasChanged = 1;
    }
    else if (paramName == "TEMP_AIR") {
        if (paramValue == 0) params.flags &= ~FLAG_TEMP_AIR;
        else if (paramValue == 1) params.flags |= FLAG_TEMP_AIR;
        hasChanged = 1;
    }
    else if (paramName == "HYGR") {
        if (paramValue == 0) params.flags &= ~FLAG_HYGR;
        else if (paramValue == 1) params.flags |= FLAG_HYGR;
        hasChanged = 1;
    }
    else if (paramName == "PRESSURE") {
        if (paramValue == 0) params.flags &= ~FLAG_PRESSURE;
        else if (paramValue == 1) params.flags |= FLAG_PRESSURE;
        hasChanged = 1;
    }
    else if (paramName=="LUMIN_LOW" && (paramValue >= 0 && paramValue <= 1023)) (params.LUMIN_LOW = paramValue) && (hasChanged=1);
    else if (paramName=="LUMIN_HIGH" && (paramValue >= 0 && paramValue <= 1023)) (params.LUMIN_HIGH = paramValue) && (hasChanged=1);
    else if (paramName=="MIN_TEMP_AIR" && (paramValue >= -40 && paramValue <= 85)) (params.MIN_TEMP_AIR = paramValue) && (hasChanged=1);
    else if (paramName=="MAX_TEMP_AIR" && (paramValue >= -40 && paramValue <= 85)) (params.MAX_TEMP_AIR = paramValue) && (hasChanged=1);
    else if (paramName=="HYGR_MIN" && (paramValue >= -40 && paramValue <= 85)) (params.HYGR_MIN = paramValue) && (hasChanged=1);
    else if (paramName=="HYGR_MAX" && (paramValue >= -40 && paramValue <= 85)) (params.HYGR_MAX = paramValue) && (hasChanged=1);
    else if (paramName=="PRESSURE_MIN" && (paramValue >= 300 && paramValue <= 1100)) (params.PRESSURE_MIN = paramValue) && (hasChanged=1);
    else if (paramName=="PRESSURE_MAX" && (paramValue >= 300 && paramValue <= 1100)) (params.PRESSURE_MAX = paramValue) && (hasChanged=1);
    else if (paramName=="LOG_INTERVAL") (params.LOG_INTERVAL = paramValue) && (hasChanged=1);
    else if (paramName=="FILE_MAX_SIZE") (params.FILE_MAX_SIZE = paramValue) && (hasChanged=1);
    else if (paramName=="TIMEOUT") (params.TIMEOUT = paramValue) && (hasChanged=1);
    else if (paramName=="RESET") resetConfig();
    else if (paramName=="VERSION") displayVersion();
    else if (paramName == "CLOCK") {
        uint8_t newHour = paramValue;
        uint8_t newMinute = Serial.parseInt();
        uint8_t newSecond = Serial.parseInt();
        if (newHour >= 0 && newHour < 24 && newMinute >= 0 && newMinute < 60 && newSecond >= 0 && newSecond < 60) {
            rtc.adjustTime(newHour, newMinute, newSecond);
            hasChanged = 1;
        }
    } else if (paramName == "DATE") {
        int newYear = paramValue;
        uint8_t newMonth = Serial.parseInt();
        uint8_t newDay = Serial.parseInt();
        if (newYear >= 0 && newMonth > 0 && newMonth <= 12 && newDay > 0 && newDay <= 31) {
            rtc.adjustDate(newYear, newMonth, newDay);
            hasChanged = 1;
        }
    } else if (paramName=="DAY") hasChanged=1;
    else Serial.println(F("Paramètre inconnu ou valeur incorrecte."));
    EEPROM.put(1, params);
    if (hasChanged) Serial.println(F("Nouvelle onfiguration sauvegardée."));
}

void resetConfig() {
    rtc.resetRTC();
    
    params.flags = FLAG_LUMIN | FLAG_TEMP_AIR | FLAG_HYGR | FLAG_PRESSURE;
    params.LOG_INTERVAL = 1;
    params.FILE_MAX_SIZE = 2048;
    params.TIMEOUT = 30;
    params.LUMIN_LOW = 255;
    params.LUMIN_HIGH = 768;
    params.MIN_TEMP_AIR = -10;
    params.MAX_TEMP_AIR = 60;
    params.HYGR_MIN = 0;
    params.HYGR_MAX = 50;
    params.PRESSURE_MIN = 850;
    params.PRESSURE_MAX = 1080;

    EEPROM.put(1, params);
    
    char buffer[30];
    strcpy_P(buffer, MSG_RESET);
    Serial.println(buffer);
}


void displayVersion() {
    Serial.print(F("Version: "));
    Serial.println(version.num);
    Serial.print(F("Numéro de lot: "));
    Serial.println(version.lot);
}




