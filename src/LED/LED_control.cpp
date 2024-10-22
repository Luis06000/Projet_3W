// #include "LED_control.h"

// ChainableLED leds(7, 8, NUM_LEDS); // Initialiser directement

// float hue = 0.0;
// boolean up = true;
// boolean ledOn = false;  // État de la LED

// void initLEDs() {
//   pinMode(BUTTON_1_PIN, INPUT_PULLUP);  // Utilisation de la résistance pull-up interne
//   pinMode(BUTTON_2_PIN, INPUT_PULLUP);
// }

// void updateLEDs() {
//   // Vérifier l'état des boutons
//   if (digitalRead(BUTTON_1_PIN) == LOW) {
//     ledOn = true;  // Bouton 1 pressé, allumer la LED
//   }

//   if (digitalRead(BUTTON_2_PIN) == LOW) {
//     ledOn = false;  // Bouton 2 pressé, éteindre la LED
//   }

//   if (ledOn) {
//     // Faire tourner les couleurs lorsque la LED est allumée
//     for (byte i = 0; i < NUM_LEDS; i++) {
//       leds.setColorHSB(i, hue, 1.0, 0.5); // Définir la couleur avec HSB
//     }

//     delay(50);

//     if (up) {
//       hue += 0.025;
//     } else {
//       hue -= 0.025;
//     }

//     if (hue >= 1.0 && up) {
//       up = false;
//     } else if (hue <= 0.0 && !up) {
//       up = true;
//     }
//   } else {
//     // Éteindre toutes les LED si ledOn est faux
//     for (byte i = 0; i < NUM_LEDS; i++) {
//       leds.setColorRGB(i, 0, 0, 0); // Mettre les LED à zéro
//     }
//   }
// }


// void setLEDColor(int r, int g, int b) {
//     for (byte i = 0; i < NUM_LEDS; i++) {
//         leds.setColorRGB(i, r, g, b); // Définir la couleur pour toutes les LEDs
//     }
// }





#include "LED_control.h"

ChainableLED leds(7, 8, NUM_LEDS); // Initialiser directement

float hue = 0.0;
boolean up = true;

void initLEDs() {
  // Aucune interaction avec les boutons ici, juste l'initialisation des LEDs
}

void updateLEDs() {
  if (ledOn) {
    // Faire tourner les couleurs lorsque la LED est allumée
    for (byte i = 0; i < NUM_LEDS; i++) {
      leds.setColorHSB(i, hue, 1.0, 0.5); // Définir la couleur avec HSB
    }

    delay(50);

    if (up) {
      hue += 0.025;
    } else {
      hue -= 0.025;
    }

    if (hue >= 1.0 && up) {
      up = false;
    } else if (hue <= 0.0 && !up) {
      up = true;
    }
  } else {
    // Éteindre toutes les LED si ledOn est faux
    for (byte i = 0; i < NUM_LEDS; i++) {
      leds.setColorRGB(i, 0, 0, 0); // Mettre les LED à zéro
    }
  }
}

void setLEDColor(int r, int g, int b) {
    for (byte i = 0; i < NUM_LEDS; i++) {
        leds.setColorRGB(i, r, g, b); // Définir la couleur pour toutes les LEDs
    }
}
