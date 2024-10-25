#ifndef RTC_H
#define RTC_H

#include <RTClib.h>

class RTC {
public:
    RTC();  // Constructeur
    bool begin();  // Initialiser le module RTC
    bool isRunning();  // Vérifier si l'horloge est en marche
    void printCurrentTime();  // Afficher l'heure actuelle

private:
    RTC_DS1307 rtc;  // Instance de RTC_DS1307
};

#endif