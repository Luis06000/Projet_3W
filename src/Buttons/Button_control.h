#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

// Déclaration des constantes pour les boutons
#define BUTTON_1_PIN 3
#define BUTTON_2_PIN 4

extern volatile bool ledOn;  // Partager l'état de la LED avec d'autres fichiers

// Déclaration des fonctions
void initButtons();
void button1Interrupt();  // Gérer l'interruption du bouton 1
void button2Interrupt();  // Gérer l'interruption du bouton 2

#endif // BUTTON_CONTROL_H