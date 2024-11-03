#include "SDCard.h"
#include "Config.h"

SDCard::SDCard(uint8_t SDPin) : 
    csPin(SDPin), 
    functional(false), 
    revision(0), 
    writeError(false) {}

bool SDCard::begin() {
    if (!SD.begin(csPin)) {
        functional = false;
        return false;
    }
    functional = true;
    currentDate = rtc.now();
    generateFileName();
    return true;
}

bool SDCard::isFunctional() {
    return functional;
}

bool SDCard::isSDCardFull() {
    if (!functional) return false;
    
    File testFile = SD.open("test.tmp", FILE_WRITE);
    if (!testFile) {
        return true;  // Si on ne peut pas créer de fichier, la carte est pleine
    }
    
    testFile.close();
    SD.remove("test.tmp");
    return false;
}

void SDCard::generateFileName() {
    DateTime now = rtc.now();
    if (now.day() != currentDate.day() || now.month() != currentDate.month() || now.year() != currentDate.year()) {
        revision = 0;
        currentDate = now;
    }
    snprintf(currentFileName, sizeof(currentFileName), "%02d%02d%02d_%01d.LOG", 
             now.year() % 100, now.month(), now.day(), revision);
}

void SDCard::openFile() {
    logFile = SD.open(currentFileName, FILE_WRITE);
}

void SDCard::closeFile() {
    if (logFile) {
        logFile.close();
    }
}

void SDCard::checkFileSize() {
    if (logFile.size() >= params.FILE_MAX_SIZE) {
        closeFile();
        
        char backupFileName[13];
        snprintf(backupFileName, sizeof(backupFileName), "%02d%02d%02d_%01d.LOG", 
                currentDate.year() % 100, currentDate.month(), currentDate.day(), revision + 1);
                
        File sourceFile = SD.open(currentFileName, FILE_READ);
        File destFile = SD.open(backupFileName, FILE_WRITE);
        
        if (sourceFile && destFile) {
            while (sourceFile.available()) {
                destFile.write(sourceFile.read());
            }
        }
        
        sourceFile.close();
        destFile.close();
        
        SD.remove(currentFileName);
        
        revision++;
        generateFileName();
    }
}

void SDCard::printToFile(const char* data) {
    if (functional && logFile) {
        if (!logFile.print(data)) {
            writeError = true;
        }
    }
}

void SDCard::printToFile(int data) {
    if (functional && logFile) {
        if (!logFile.print(data)) {
            writeError = true;
        }
    }
}

void SDCard::printToFile(uint16_t data) {
    if (functional && logFile) {
        if (!logFile.print(data)) {
            writeError = true;
        }
    }
}

void SDCard::printToFile(float data, int precision) {
    if (functional && logFile) {
        if (!logFile.print(data, precision)) {
            writeError = true;
        }
    }
}