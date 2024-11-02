#ifndef RTC_H
#define RTC_H

#include <RTClib.h>

class RTC {
public:
    RTC();  // Constructeur
    bool begin();  // Initialiser le module RTC
    bool isRunning();  // Vérifier si l'horloge est en marche
    const char* currentTime();  // Retourner l'heure formatée
    void adjustClock(int newHour, int newMinute, int newSecond);
    void adjustDate(int newMonth, int newDay, int newYear);
    void resetRTC();

    RTC_DS1307 rtc;  // Instance de RTC_DS1307

private:
    char buffer[33];
};

extern RTC rtcSensor;

#endif