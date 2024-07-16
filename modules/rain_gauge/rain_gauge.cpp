//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "rain_gauge.h"

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void initRainGauge(RainGauge_t* rainGauge) {
    rainGauge->accumulatedRain = 0;

    for(int i = 0; i < MAX_AMOUNT_OF_REGISTERS; i++) {
        rainGauge->lastRegistrations[i] = 0;
    }

    initDebouncer(&rainGauge->debouncer);
}

void saveRainMeasure(RainGauge_t* rainGauge) {

}

void updateRainMeasure(RainGauge_t* rainGauge) {
    updateDebouncer(&rainGauge->debouncer);
    if(!rainGauge->debouncer.isADebounce){
        rainGauge->accumulatedRain++;
    }
}
