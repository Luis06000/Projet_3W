#include "./LED/LED_control.h"
#include "./Modes/Modes.h"
#include "./Sensors/Light/LightSensor.h"
#include "Sensors/THP/BME280Sensor.h"
#include "./RTC/RTC.h"
#include "./Buttons/Button_control.h"
#include "Config.h"
#include "./SDCard/SDCard.h"
#include "./GPS/GPS.h"

#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "Wire.h"
#include <SPI.h>
#include "AsyncDelay.h"
#include "ChainableLED.h"


RTC rtcSensor;
BME280Sensor bmeSensor;
LightSensor lightSensor;


unsigned long lastPrintTime = 0;


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
    loadConfigFromEEPROM();
    // setupSDCard();
    // setupGPS();
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
    updateModes();
    if (millis() - lastPrintTime >= LOG_INTERVAL) {
        lastPrintTime = millis();
        // rtcSensor.printCurrentTime();
        lightSensor.printLightValue();
        bmeSensor.readSensor();
        // logData();
        // readGPSData();
    }
}