// #include "Modes.h"
// #include "./LED/LED_control.h"
// #include "Buttons/Button_control.h"
// #include "Config.h"

// uint8_t currentMode = MODE_STANDARD;
// uint8_t previousMode = MODE_STANDARD;

// static bool lastButton1State = HIGH, lastButton2State = HIGH;
// static unsigned long button1PressTime = 0, button2PressTime = 0;
// static const unsigned long buttonHoldDuration = 5000;
// static bool button1Lock = false, button2Lock = false;

// void setMode(uint8_t mode, uint8_t r, uint8_t g, uint8_t b) {
//     currentMode = mode;
//     setLEDColor(r, g, b);
// }

// void initModes() {
//     pinMode(BUTTON_1_PIN, INPUT_PULLUP);
//     pinMode(BUTTON_2_PIN, INPUT_PULLUP);

//     if (digitalRead(BUTTON_2_PIN) == LOW) {
//         setMode(MODE_CONFIGURATION, 255, 255, 0);
//         modeConfiguration();
//     }
//     else setMode(MODE_STANDARD, 0, 255, 0);
// }

// void updateModes() {
//     bool button1State = digitalRead(BUTTON_1_PIN);
//     bool button2State = digitalRead(BUTTON_2_PIN);

//     // Mode Standard <-> Economy
//     if (button1State == LOW && lastButton1State == HIGH) {
//         button1PressTime = millis();
//         button1Lock = false;
//     }

//     if (button1State == LOW && (millis() - button1PressTime >= buttonHoldDuration) && !button1Lock) {
//         if (currentMode == MODE_STANDARD) setMode(MODE_ECONOMY, 0, 0, 255);
//         else if (currentMode == MODE_ECONOMY) setMode(MODE_STANDARD, 0, 255, 0);
//         button1Lock = true;
//     }

//     if (button1State == HIGH) {
//         button1Lock = false;
//     }

//     // Mode Maintenance
//     if (button2State == LOW && lastButton2State == HIGH) {
//         button2PressTime = millis();
//         button2Lock = false;
//     }

//     if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration) && !button2Lock) {
//         if (currentMode == MODE_MAINTENANCE) 
//             setMode(previousMode, previousMode == MODE_STANDARD ? 0 : 0, 
//                    previousMode == MODE_STANDARD ? 255 : 0, 
//                    previousMode == MODE_STANDARD ? 0 : 255);
//         else {
//             previousMode = currentMode;
//             setMode(MODE_MAINTENANCE, 255, 128, 0);
//         }
//         button2Lock = true;
//     }

//     if (button2State == HIGH) {
//         button2Lock = false;
//     }

//     lastButton1State = button1State;
//     lastButton2State = button2State;
// }

// void modeConfiguration() {
//     Serial.println(F("\nEntrez le nom du paramètre et sa nouvelle valeur, séparés par un espace:\n"));
//     Config();
    
//     static unsigned long lastActivityTime = 0;
//     const unsigned long inactivityDuration = 1800000;
//     bool button2State;

//     while (true) {
//         if (Serial.available() > 0) {
//             String paramName = Serial.readStringUntil(' ');
//             for (uint8_t i = 0; i < paramName.length(); i++) {
//                 paramName[i] = toupper(paramName[i]);
//             }
//             int paramValue = Serial.parseInt();
//             updateConfigParameter(paramName, paramValue);
//             lastActivityTime = millis();
//         }

//         if (millis() - lastActivityTime >= inactivityDuration) {
//             setMode(MODE_STANDARD, 0, 255, 0);
//             return;
//         }

//         button2State = digitalRead(BUTTON_2_PIN);
//         if (button2State == LOW && lastButton2State == HIGH) {
//             button2PressTime = millis();
//             button2Lock = false;
//         }
        
//         if (button2State == LOW && (millis() - button2PressTime >= buttonHoldDuration) && !button2Lock) {
//             setMode(MODE_STANDARD, 0, 255, 0);
//             button2Lock = true;
//             return;
//         }
        
//         lastButton2State = button2State;
//     }
// }






#include "Modes.h"
#include "./LED/LED_control.h"
#include "Buttons/Button_control.h"
#include "Config.h"

uint8_t currentMode = MODE_STANDARD;
uint8_t buttonStatus = 0;
static uint8_t previousMode = MODE_STANDARD;
static const uint16_t HOLD_DURATION = 5000;
static uint32_t button1PressTime = 0;
static uint32_t button2PressTime = 0;

void setMode(uint8_t mode, uint8_t r, uint8_t g, uint8_t b) {
    currentMode = mode;
    setLEDColor(r, g, b);
}

void initModes() {
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);

    if (!(digitalRead(BUTTON_2_PIN))) {
        setMode(MODE_CONFIGURATION, 255, 255, 0);
        modeConfiguration();
    } else {
        setMode(MODE_STANDARD, 0, 255, 0);
    }
}

void updateModes() {
    uint8_t b1 = digitalRead(BUTTON_1_PIN);
    uint8_t b2 = digitalRead(BUTTON_2_PIN);
    uint32_t now = millis();

    // Gestion du bouton 1
    if (!b1 && !(buttonStatus & BTN_STATE_1)) {
        button1PressTime = now;
        buttonStatus &= ~BTN_LOCK_1;
        buttonStatus |= BTN_STATE_1;
    }
    else if (b1 && (buttonStatus & BTN_STATE_1)) {
        buttonStatus &= ~BTN_STATE_1;
    }

    if ((buttonStatus & BTN_STATE_1) && !b1 && (now - button1PressTime >= HOLD_DURATION) && !(buttonStatus & BTN_LOCK_1)) {
        if (currentMode == MODE_STANDARD) {
            setMode(MODE_ECONOMY, 0, 0, 255);
        } else if (currentMode == MODE_ECONOMY) {
            setMode(MODE_STANDARD, 0, 255, 0);
        }
        buttonStatus |= BTN_LOCK_1;
    }

    // Gestion du bouton 2
    if (!b2 && !(buttonStatus & BTN_STATE_2)) {
        button2PressTime = now;
        buttonStatus &= ~BTN_LOCK_2;
        buttonStatus |= BTN_STATE_2;
    }
    else if (b2 && (buttonStatus & BTN_STATE_2)) {
        buttonStatus &= ~BTN_STATE_2;
    }

    if ((buttonStatus & BTN_STATE_2) && !b2 && (now - button2PressTime >= HOLD_DURATION) && !(buttonStatus & BTN_LOCK_2)) {
        if (currentMode == MODE_MAINTENANCE) {
            setMode(previousMode, 
                   0, 
                   previousMode == MODE_STANDARD ? 255 : 0,
                   previousMode == MODE_STANDARD ? 0 : 255);
        } else {
            previousMode = currentMode;
            setMode(MODE_MAINTENANCE, 255, 128, 0);
        }
        buttonStatus |= BTN_LOCK_2;
    }
}

void modeConfiguration() {
    const uint32_t TIMEOUT = 1800000UL;
    uint32_t lastActivity = millis();
    uint8_t b2;
    
    Serial.println(F("\nConfig: <param> <valeur>\n"));
    Config();

    while (1) {
        if (Serial.available()) {
            String param = Serial.readStringUntil(' ');
            for (uint8_t i = 0; i < param.length(); i++) {
                param[i] = toupper(param[i]);
            }
            int val = Serial.parseInt();
            updateConfigParameter(param, val);
            lastActivity = millis();
        }

        if (millis() - lastActivity >= TIMEOUT) {
            setMode(MODE_STANDARD, 0, 255, 0);
            return;
        }

        b2 = digitalRead(BUTTON_2_PIN);
        if (!b2 && !(buttonStatus & BTN_STATE_2)) {
            button2PressTime = millis();
            buttonStatus &= ~BTN_LOCK_2;
            buttonStatus |= BTN_STATE_2;
        }
        
        if ((buttonStatus & BTN_STATE_2) && !b2 && 
            (millis() - button2PressTime >= HOLD_DURATION) && 
            !(buttonStatus & BTN_LOCK_2)) {
            setMode(MODE_STANDARD, 0, 255, 0);
            return;
        }
    }
}