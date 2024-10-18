#include "./LED/LED_control.h"
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "./LED/LED_control.h" // Inclure le fichier d'en-tête approprié
#include "./Modes/Modes.h" // Inclure le fichier d'en-tête des modes



void setup() {
    initLEDs();  // Initialiser les LEDs et les boutons
    initModes(); // Initialiser les modes
}

void loop() {
    updateModes(); // Mettre à jour le mode en fonction des entrées utilisateur

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