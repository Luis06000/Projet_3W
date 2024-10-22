// #ifndef BUTTON_CONTROL_H
// #define BUTTON_CONTROL_H

// // Déclaration des constantes pour les boutons
// #define BUTTON_1_PIN 2  // INT0
// #define BUTTON_2_PIN 3  // INT1

// // Déclaration des fonctions
// void initButtons();
// void handleButton1Press();
// void handleButton2Press();

// #endif // BUTTON_CONTROL_H





#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

// Déclaration des constantes pour les boutons
#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3

extern volatile bool ledOn;  // Partager l'état de la LED avec d'autres fichiers

// Déclaration des fonctions
void initButtons();
void button1Interrupt();  // Gérer l'interruption du bouton 1
void button2Interrupt();  // Gérer l'interruption du bouton 2

#endif // BUTTON_CONTROL_H