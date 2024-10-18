#ifndef LIGHT_H
#define LIGHT_H

// Définition de la classe LightSensor
class LightSensor {
public:
    LightSensor(int lightPin, int threshold);  // Supprimer le paramètre led
    void setup();
    void loop();
private:
    int lightSensorPin;
    int lightThreshold;
};

#endif // LIGHT_H