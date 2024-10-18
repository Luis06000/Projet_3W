#include "./LED/LED_control.h"
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "./LED/LED_control.h" // Inclure le fichier d'en-tête approprié
#include "./Modes/Modes.h" // Inclure le fichier d'en-tête des modes
#include "Wire.h"
#include <SPI.h>
#include "AsyncDelay.h"
#include "ChainableLED.h"
#include "./Sensors/Light/LightSensor.h"


#define LIGHT_SENSOR_PIN A0
#define LIGHT_THRESHOLD 300

LightSensor lightSensor(LIGHT_SENSOR_PIN, LIGHT_THRESHOLD);

void setup() {
    Serial.begin(9600);  // Initialiser la communication série
    initLEDs();  // Initialiser les LEDs et les boutons
    initModes(); // Initialiser les modes
    lightSensor.setup();
}

void loop() {
    updateModes(); // Mettre à jour le mode en fonction des entrées utilisateur
    lightSensor.loop();

    switch (currentMode) {
        case MODE_STANDARD:
            modeStandard();
            break;
        case MODE_ECONOMY:
            modeEconomy();
            break;
        case MODE_MAINTENANCE:
            modeMaintenance();
            break;
    }
}