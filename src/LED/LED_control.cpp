#include "LED_control.h"

ChainableLED leds(7, 8, NUM_LEDS); // Initialiser directement

void initLEDs() {}

void updateLEDs() {
  static float hue = 0.0;
  static bool up = true;

  if (ledOn) {
    // Faire tourner les couleurs lorsque la LED est allumée
    for (byte i = 0; i < NUM_LEDS; i++) {
      leds.setColorHSB(i, hue, 1.0, 0.5); // Définir la couleur avec HSB
    }

    delay(50);

    hue += up ? 0.025 : -0.025;

    if (hue >= 1.0) up = false;
    else if (hue <= 0.0) up = true;
  } else {
      setLEDColor(0, 0, 0); // Éteindre toutes les LEDs
  }
}

void setLEDColor(uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        leds.setColorRGB(i, r, g, b); // Définir la couleur pour toutes les LEDs
    }
}
