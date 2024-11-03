#include "./LED/LED_control.h"
// #include "./Modes/Modes.h"
#include "./Sensors/Light/LightSensor.h"
#include "Sensors/THP/BME280Sensor.h"
#include "./RTC/RTC.h"
// #include "./Buttons/Button_control.h"
#include "Config.h"
#include "./SDCard/SDCard.h"
#include "./GPS/GPS.h"

#include <SoftwareSerial.h>


RTC rtcSensor;
BME280Sensor bmeSensor;
LightSensor lightSensor;
GPSSensor gps;
SDCard sdCard(4);


long lastPrintTime = 0;
int c = 0;


void setup() {
    Serial.begin(9600);
    if (!rtcSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(0, 0, 255);
          delay(500);
        }
    };
    rtcSensor.setDefaultTime();
    if (!lightSensor.begin() || !bmeSensor.begin()) {
        while (1)
        {
          setLEDColor(255, 0, 0);
          delay(500);
          setLEDColor(0, 255, 0);
          delay(500);
        }
    };
    // initButtons();
    // initModes();
    initLEDs();
    gps.setup();
    sdCard.begin();
}

void loop() {
    // if (isSDCardFull()) {
    //     while (1)
    //     {
    //       setLEDColor(255, 0, 0);
    //       delay(500);
    //       setLEDColor(255, 255, 255);
    //       delay(500);
    //     }
    // }
    // if (ERREUR) {
    //     while (1)
    //     {
    //       setLEDColor(255, 0, 0);
    //       delay(333);
    //       setLEDColor(0, 255, 0);
    //       delay(637);
    //     }
    // };
    // updateModes();
    // if ((millis() - lastPrintTime) >= (params.LOG_INTERVAL*60000)) {
    //     lastPrintTime = millis();
    //     rtcSensor.printCurrentTime();
    //     if (params.LUMIN) lightSensor.printLightValue();
    //     bmeSensor.readSensor();
    //     readGPSData();
    //     // logData();
    // }




    
    // if (currentMode==MODE_MAINTENANCE) {
        // if ((millis() - lastPrintTime) >= (params.LOG_INTERVAL*60000)) {
        //     lastPrintTime = millis();
        //     Serial.print(rtcSensor.currentTime()), Serial.print(F(" "));
        //     if (params.LUMIN) Serial.print(F("Lumière:")), Serial.print(lightSensor.LightValue()), Serial.print(F(" "));
        //     if (params.TEMP_AIR) Serial.print(F("T:")), Serial.print(bmeSensor.Temperature()), Serial.print(F(" °C")), Serial.print(F(" "));
        //     if (params.HYGR) Serial.print(F("H:")), Serial.print(bmeSensor.Humidity()), Serial.print(F(" %")), Serial.print(F(" "));
        //     if (params.PRESSURE) Serial.print(F("P:")), Serial.print(bmeSensor.Pressure()), Serial.print(F(" hPa")), Serial.print(F(" "));
        //     gps.readData();
        //     if (gps.Latitude()!=0) Serial.print(F("Latitude:")), Serial.print(gps.Latitude(),6), Serial.print(F(" "));
        //     else Serial.print(F("Latitude:NA "));
        //     if (gps.Longitude()!=0) Serial.print(F("Longitude:")), Serial.print(gps.Longitude(),6), Serial.print(F(" "));
        //     else Serial.print(F("Longitude:NA "));
        // }
    // }

    if (sdCard.isFunctional()) {
        // Récupération et écriture de l'heure
        sdCard.printToFile(rtcSensor.currentTime());
        sdCard.printToFile(" ");

        // Données du capteur de lumière
        if (params.LUMIN) sdCard.printToFile("Lumière:"), sdCard.printToFile(lightSensor.LightValue()), sdCard.printToFile(" ");

        // Données BME280
        if (params.TEMP_AIR) sdCard.printToFile("T:"), sdCard.printToFile(bmeSensor.Temperature()), sdCard.printToFile(" °C ");
        if (params.HYGR) sdCard.printToFile("H:"), sdCard.printToFile(bmeSensor.Humidity()), sdCard.printToFile(" % ");
        if (params.PRESSURE) sdCard.printToFile("P:"), sdCard.printToFile(bmeSensor.Pressure()), sdCard.printToFile(" hPa ");

        // Données GPS
        if (gps.Latitude() != 0) sdCard.printToFile("Latitude:"), sdCard.printToFile(gps.Latitude(), 6), sdCard.printToFile(" ");
        else sdCard.printToFile("Latitude:NA ");
        if (gps.Longitude() != 0) sdCard.printToFile("Longitude:"), sdCard.printToFile(gps.Longitude(), 6), sdCard.printToFile(" ");
        else sdCard.printToFile("Longitude:NA ");

        sdCard.printToFile("\n");
        sdCard.checkFileSize();
        sdCard.closeFile();
        c++;
        Serial.println(c);
    }


    if (gps.InvalidLocationCount() >= 2 || invalidBMECount >= 2) ERREUR = 1;
}
