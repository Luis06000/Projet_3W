#include "./LED/LED_control.h"
#include "./Modes/Modes.h"
#include "./Sensors/Light/LightSensor.h"
#include "Sensors/THP/BME280Sensor.h"
#include "./RTC/RTC.h"
#include "./Buttons/Button_control.h"
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "Wire.h"
#include <SPI.h>
#include "AsyncDelay.h"
#include "ChainableLED.h"


RTC rtcSensor;
BME280Sensor bmeSensor;
LightSensor lightSensor;



void setup() {
    Serial.begin(9600);
    if (!rtcSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(255, 255, 0);
          delay(500);
        }
    };
    rtcSensor.adjustTimeFromSerial();
    if (!lightSensor.begin() || !bmeSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(0, 255, 0);
          delay(500);
        }
    };
    initLEDs();
    initButtons();
    initModes();
}

void loop() {
    updateModes();
    if (currentMode == MODE_CONFIGURATION) {
        return ;
    }
    lightSensor.printLightValue();
    bmeSensor.readSensor();
    rtcSensor.printCurrentTime();
    // delay(600000);
    delay(2000);

    switch (currentMode) {
        case MODE_STANDARD:
            modeStandard();
            break;
        case MODE_ECONOMY:
            modeEconomique();
            break;
        case MODE_MAINTENANCE:
            modeMaintenance();
            break;
    }
}