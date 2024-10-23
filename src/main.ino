#include "./LED/LED_control.h"
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "./Modes/Modes.h" // Inclure le fichier d'en-tête des modes
#include "Wire.h"
#include <SPI.h>
#include "AsyncDelay.h"
#include "ChainableLED.h"
#include "./Sensors/Light/LightSensor.h"
#include "Sensors/THP/BME280Sensor.h"
#include "./RTC/RTC.h"
#include "./Buttons/Button_control.h"

RTC rtcSensor;
BME280Sensor bmeSensor;


#define LIGHT_SENSOR_PIN A0
#define LIGHT_THRESHOLD 300

LightSensor lightSensor(LIGHT_SENSOR_PIN, LIGHT_THRESHOLD);

void setup() {
    Serial.begin(9600);  // Initialiser la communication série
    initLEDs();  // Initialiser les LEDs et les boutons
    initButtons();
    initModes(); // Initialiser les modes
    lightSensor.setup();
    bmeSensor.begin();
    if (!rtcSensor.begin()) {
        while (!rtcSensor.isRunning())
        {
          setLEDColor(255, 0, 0);
          delay(1000);
          setLEDColor(255, 255, 0);
          delay(1000);
        }
    };
    rtcSensor.adjustTime();

}

void loop() {
    updateModes();
    if (currentMode == MODE_CONFIGURATION) {
        return ; // Ne pas changer de mode
    }
    lightSensor.loop();
    bmeSensor.readSensor();
    rtcSensor.printCurrentTime();
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