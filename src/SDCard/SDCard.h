#ifndef SDCARD_H
#define SDCARD_H

#include <SD.h>
#include "RTC/RTC.h"

class SDCard {
public:
    SDCard(uint8_t csPin);
    bool begin();
    bool isFunctional();
    bool isSDCardFull();
    bool hasWriteError() const { return writeError; };
    void openFile();
    void closeFile();
    void printToFile(const char* data);
    void printToFile(int data);
    void printToFile(uint16_t data);
    void printToFile(float data, int precision = 2);
    void checkFileSize();

private:
    void generateFileName();
    uint8_t csPin;
    File logFile;
    char currentFileName[13];
    DateTime currentDate;
    bool functional;
    uint8_t revision;
    bool writeError;
};

#endif
