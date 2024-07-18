//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "rain_gauge.h"

//-----------------------------------------------------------------------------
// Defines and Macros
//-----------------------------------------------------------------------------

#define REED_SWITCH_PIN D0

//-----------------------------------------------------------------------------
// Private Variables
//-----------------------------------------------------------------------------

static Debouncer_t reedSwitchDebouncer = {true, DigitalIn(REED_SWITCH_PIN), UP};
static RainGauge_t rainGauge;
static RainGauge_t lastRegistrations[MAX_AMOUNT_OF_REGISTERS];
static uint8_t registrationsIndex;
//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void initRainGauge() {
    rainGauge.accumulatedRain = 0;
    rainGauge.date = getDateTimeFromEpoch(time(NULL));
    registrationsIndex = 0;
}

void saveRainMeasure() {
    lastRegistrations[registrationsIndex] = rainGauge;
    registrationsIndex = ++registrationsIndex % MAX_AMOUNT_OF_REGISTERS;
}

void resetRainGauge() {
    rainGauge.accumulatedRain = 0;
    rainGauge.date = getDateTimeFromEpoch(time(NULL));
}

void updateRainMeasure() {
    updateDebouncer(&reedSwitchDebouncer);
    if(!reedSwitchDebouncer.isADebounce){
        if(isSameDate()) {
            rainGauge.accumulatedRain++;
        } else {
            saveRainMeasure();
            resetRainGauge();
        }
    }
}

unsigned int getAccumulatedRain() {
    return rainGauge.accumulatedRain;
}

bool isSameDate() {
    DateTime_t timeNow = getDateTimeFromEpoch(time(NULL));
    return (rainGauge.date.year == timeNow.year && rainGauge.date.month == timeNow.month && rainGauge.date.day == timeNow.day);
}