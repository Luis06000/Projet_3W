#ifndef MODES_H
#define MODES_H

#include "Config.h"
#include "./LED/LED_control.h"
#include "./Buttons/Button_control.h"
#include <Arduino.h>
#include <ctype.h>

enum Mode { MODE_STANDARD, MODE_ECONOMY, MODE_MAINTENANCE, MODE_CONFIGURATION };
extern Mode currentMode;

void initModes();
void updateModes();
void modeStandard();
void modeEconomique();
void modeMaintenance();
void modeConfiguration();

#endif // MODES_H
