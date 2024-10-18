#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include "AsyncDelay.h"

// Créer une instance de la classe RTC_DS1307
RTC_DS1307 rtc;

void setup () {
  Serial.begin(9600);  // Initialiser la communication série
  Wire.begin();  // Initialiser le bus I2C

  // Vérifier si le module RTC est présent
  if (!rtc.begin()) {
    Serial.println("Erreur : Impossible de trouver le module RTC.");
    while (1);
  }

  // Vérifier si l'horloge est en marche
  if (!rtc.isrunning()) {
    Serial.println("L'horloge RTC ne fonctionne pas, initialisation en cours...");
    // Si l'horloge ne fonctionne pas, définir l'heure actuelle
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  // Obtenir l'heure actuelle depuis le RTC
  DateTime now = rtc.now();

  // Afficher la date et l'heure
  Serial.print("Date: ");
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" Heure: ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(1000);  // Mettre à jour toutes les secondes
}