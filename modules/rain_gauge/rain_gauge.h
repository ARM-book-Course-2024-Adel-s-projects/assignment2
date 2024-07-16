#ifndef _RAIN_GAUGE_
#define _RAIN_GAUGE_

//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "debouncer.h"
#include "mbed.h"

//-----------------------------------------------------------------------------
// Defines and Macros
//-----------------------------------------------------------------------------

#define MAX_AMOUNT_OF_REGISTERS 100

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

typedef struct RainGauge {
    unsigned int accumulatedRain;
    unsigned int lastRegistrations[MAX_AMOUNT_OF_REGISTERS];
} RainGauge_t;

//-----------------------------------------------------------------------------
// Public Functions Prototypes
//-----------------------------------------------------------------------------

void initRainGauge();
void updateRainMeasure();
void saveRainMeasure();
unsigned int getAccumulatedRain();

#endif