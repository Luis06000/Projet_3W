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


RTC rtcSensor;
BME280Sensor bmeSensor;
LightSensor lightSensor;


long lastPrintTime = 0;


void setup() {
    Serial.begin(9600);
    if (!rtcSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(0, 0, 255);
          delay(500);
        }
    };
    if (!lightSensor.begin() || !bmeSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(0, 255, 0);
          delay(500);
        }
    };
    initButtons();
    initModes();
    initLEDs();
    setupGPS();
    // setupSDCard();
}

void loop() {
    // if (isSDCardFull()) {
    //     while (1)
    //     {
    //       setLEDColor(255, 0, 0);
    //       delay(500);
    //       setLEDColor(255, 255, 255);
    //       delay(500);
    //     }
    // }
    // if (ERREUR) {
    //     while (1)
    //     {
    //       setLEDColor(255, 0, 0);
    //       delay(333);
    //       setLEDColor(0, 255, 0);
    //       delay(637);
    //     }
    // };
    updateModes();
    // if ((millis() - lastPrintTime) >= (params.LOG_INTERVAL*60000)) {
    //     lastPrintTime = millis();
    //     rtcSensor.printCurrentTime();
    //     if (params.LUMIN) lightSensor.printLightValue();
    //     bmeSensor.readSensor();
    //     readGPSData();
    //     // logData();
    // }
    if (currentMode==MODE_STANDARD) {
        if ((millis() - lastPrintTime) >= (params.LOG_INTERVAL*60000)) {
            lastPrintTime = millis();
            Serial.print(rtcSensor.currentTime()), Serial.print(" ");
            if (params.LUMIN) Serial.print("Lumière:"), Serial.print(lightSensor.LightValue()), Serial.print(" ");
            // bmeSensor.readSensor();
            // readGPSData();
        }
    }
}
