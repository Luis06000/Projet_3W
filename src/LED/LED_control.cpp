#include "LED_control.h"
#include "Buttons/Button_control.h"

ChainableLED leds(7, 8, NUM_LEDS); // Initialiser directement

void initLEDs() {}

void setLEDColor(uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        leds.setColorRGB(i, r, g, b); // Définir la couleur pour toutes les LEDs
    }
}
