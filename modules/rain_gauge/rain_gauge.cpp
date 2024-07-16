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

static Debouncer_t reedSwitchDebouncer;
static RainGauge_t rainGauge;

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void initRainGauge() {
    rainGauge.accumulatedRain = 0;

    for(int i = 0; i < MAX_AMOUNT_OF_REGISTERS; i++) {
        rainGauge.lastRegistrations[i] = 0;
    }

    initDebouncer(&reedSwitchDebouncer, REED_SWITCH_PIN);
}

void saveRainMeasure() {

}

void updateRainMeasure() {
    updateDebouncer(&reedSwitchDebouncer);
    if(!reedSwitchDebouncer.isADebounce){
        rainGauge.accumulatedRain++;
    }
}

unsigned int getAccumulatedRain() {
    return rainGauge.accumulatedRain;
}
