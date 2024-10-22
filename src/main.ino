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
#include "Sensors/THPA/BME280Sensor.h"
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
    Serial.println(F("Initialisation du capteur BME280..."));

    if (!bmeSensor.begin()) {  // Initialiser le capteur
        Serial.println("Erreur de communication avec le capteur BME280.");
        while (1);
    }
}

void loop() {
    updateModes(); // Mettre à jour le mode en fonction des entrées utilisateur
    lightSensor.loop();
    bmeSensor.readSensor();  // Lire les valeurs du capteur
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