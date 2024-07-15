//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "rain_gauge.h"

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void initRainGauge(RainGauge_t* rainGauge, Debouncer_t debouncer) {
    rainGauge->debouncer = debouncer;
    rainGauge->accumulatedRain = 0;

    for(int i = 0; i < MAX_AMOUNT_OF_REGISTERS; i++) {
        rainGauge->lastRegistrations[i] = 0;
    }
}

void saveRainMeasure(RainGauge_t* rainGauge) {

}

void updateRainMeasure(RainGauge_t* rainGauge) {
    updateDebouncer(&rainGauge->reedSwitch);
    
    if(!rainGauge->reedSwitch.isADebounce) {
        rainGauge->accumulatedRain++;
    }
}