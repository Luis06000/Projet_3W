#include "./LED/LED_control.h"
#include "./Modes/Modes.h"
#include "./Sensors/Light/LightSensor.h"
#include "Sensors/THP/BME280Sensor.h"
#include "./RTC/RTC.h"
#include "./Buttons/Button_control.h"
#include "Config.h"
#include "./SDCard/SDCard.h"
#include "./GPS/GPS.h"

#include <SoftwareSerial.h>


RTC rtc;
BME280Sensor bmeSensor;
LightSensor lightSensor;
GPSSensor gps(10, 11);
SDCard sdCard(4);


void setup() {
    Serial.begin(9600);
    if (!rtc.begin()) {
        while (1) {
            setLEDColor(255, 0, 0);
            delay(500);
            setLEDColor(0, 0, 255);
            delay(500);
        }
    }
    rtc.setDefaultTime();
    if (!lightSensor.begin() || !bmeSensor.begin()) {
        while (1) {
            setLEDColor(255, 0, 0);
            delay(500);
            setLEDColor(0, 255, 0);
            delay(500);
        }
    }
    // if (!sdCard.begin()) {
    //     while (1) {
    //         setLEDColor(255, 0, 0);
    //         delay(333);
    //         setLEDColor(255, 255, 255);
    //         delay(667);
    //     }
    // }
    initButtons();
    initModes();
    initLEDs();
    gps.begin();
}

void loop() {
    // if (sdCard.isSDCardFull()) {
    //     while (1)
    //     {
    //       setLEDColor(255, 0, 0);
    //       delay(500);
    //       setLEDColor(255, 255, 255);
    //       delay(500);
    //     }
    // }
    // if (sdCard.hasWriteError()) {
    //     while (1) {
    //         setLEDColor(255, 0, 0);
    //         delay(333);
    //         setLEDColor(255, 255, 255);
    //         delay(667);
    //     }
    // }
    if (ERREUR) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(333);
          setLEDColor(0, 255, 0);
          delay(667);
        }
    };
    if (gps.InvalidLocationCount() >= 1) {
        while (1) {
            setLEDColor(255, 0, 0);
            delay(333);
            setLEDColor(255, 255, 0);
            delay(667);
        }
    }

    static unsigned long lastPrintTime = 0;
    // static bool skipGPS = false;
    unsigned long interval = (params.LOG_INTERVAL * 60000UL); //////////////////////////////////////////
    const BME280Data& sensorData = bmeSensor.readData();
    updateModes();


    // // ENREGISTREMENT DES DONNEES STANDARD ET ECONOMY
    if (currentMode == MODE_ECONOMY) interval *= 2;

    if ((millis() - lastPrintTime) >= interval) {
        lastPrintTime = millis();
        
    //     if (currentMode == MODE_STANDARD || (currentMode == MODE_ECONOMY && !skipGPS)) gps.readData();
    //     if (sdCard.isFunctional()) {
    //         sdCard.openFile();
            
    //         sdCard.printToFile(rtc.currentTime());
    //         sdCard.printToFile(" ");
    
    //         // Données du capteur de lumière
    //         if (params.flags & FLAG_LUMIN) {
    //             sdCard.printToFile("Lumière:");
    //             const LightData& lightData = lightSensor.readData();
    //             if (lightData.valid) sdCard.printToFile(lightData.value);
    //             else sdCard.printToFile("NA");
    //             sdCard.printToFile(" ");
    //         }
    
    //         // Données BME280
    //         if (params.flags & FLAG_TEMP_AIR) {
    //             sdCard.printToFile("T:");
    //             if (sensorData.validTemp) {
    //                 sdCard.printToFile(sensorData.temp, 2);
    //                 sdCard.printToFile(" °C");
    //             } else sdCard.printToFile("NA");
    //             sdCard.printToFile(" ");
    //         }
    
    //         if (params.flags & FLAG_HYGR) {
    //             sdCard.printToFile("H:");
    //             if (sensorData.validHum) {
    //                 sdCard.printToFile(sensorData.humidity, 2);
    //                 sdCard.printToFile(" %");
    //             } else sdCard.printToFile("NA");
    //             sdCard.printToFile(" ");
    //         }
    
    //         if (params.flags & FLAG_PRESSURE) {
    //             sdCard.printToFile("P:");
    //             if (sensorData.validPress) {
    //                 sdCard.printToFile(sensorData.pressure, 2);
    //                 sdCard.printToFile(" hPa");
    //             } else sdCard.printToFile("NA");
    //             sdCard.printToFile(" ");
    //         }
            
    //         // Données GPS
    //         if (currentMode == MODE_STANDARD || (currentMode == MODE_ECONOMY && !skipGPS)) {
    //             if (gps.Latitude() != 0) {
    //                 sdCard.printToFile("Latitude:");
    //                 sdCard.printToFile(gps.Latitude(), 6);
    //                 sdCard.printToFile(" ");
    //             } else sdCard.printToFile("Latitude:NA ");
    
    //             if (gps.Longitude() != 0) {
    //                 sdCard.printToFile("Longitude:");
    //                 sdCard.printToFile(gps.Longitude(), 6);
    //                 sdCard.printToFile(" ");
    //             } else sdCard.printToFile("Longitude:NA ");
    //         }
    
    //         sdCard.printToFile("\n");
    //         sdCard.checkFileSize();
    //         sdCard.closeFile();
    //     } else {
    //         Serial.println(F("Erreur carte SD"));
    //     }
    
    //     if (currentMode == MODE_ECONOMY) skipGPS = !skipGPS;
    //     else skipGPS = false;
    // }




    // AFFICHAGE DES DONNEES MAINTENANCE
        if (currentMode==MODE_MAINTENANCE) { /////////////////////////////////////////////////////////////////
            Serial.println(), Serial.print(rtc.currentTime()), Serial.print(F(" "));
            if (params.flags & FLAG_LUMIN) {
                Serial.print(F("Lumière:"));
                const LightData& lightData = lightSensor.readData();
                if (lightData.valid) Serial.print(lightData.value);
                else Serial.print(F("NA"));
                Serial.print(F(" "));
            }
            if (params.flags & FLAG_TEMP_AIR) {
                Serial.print(F("T:"));
                if (sensorData.validTemp) Serial.print(sensorData.temp, 2), Serial.print(F(" °C"));
                else Serial.print(F("NA"));
                Serial.print(F(" "));
            }
            if (params.flags & FLAG_HYGR) {
                Serial.print(F("H:"));
                if (sensorData.validHum) Serial.print(sensorData.humidity, 2), Serial.print(F(" %"));
                else Serial.print(F("NA"));
                Serial.print(F(" "));
            }
            if (params.flags & FLAG_PRESSURE) {
                Serial.print(F("P:"));
                if (sensorData.validPress) Serial.print(sensorData.pressure, 2), Serial.print(F(" hPa"));
                else Serial.print(F("NA"));
                Serial.print(F(" "));
            }
            gps.readData();
            if (gps.Latitude()!=0) Serial.print(F("Latitude:")), Serial.print(gps.Latitude(),6), Serial.print(F(" "));
            else Serial.print(F("Latitude:NA "));
            if (gps.Longitude()!=0) Serial.print(F("Longitude:")), Serial.print(gps.Longitude(),6), Serial.print(F(" "));
            else Serial.print(F("Longitude:NA "));
        }
    }
    if (bmeSensor.InvalidBMECount() >= 2 || lightSensor.InvalidLightCount() >= 2) ERREUR = 1;
}
