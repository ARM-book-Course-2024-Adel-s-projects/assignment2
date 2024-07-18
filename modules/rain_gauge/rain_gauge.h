#ifndef _RAIN_GAUGE_
#define _RAIN_GAUGE_

//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "debouncer.h"
#include "date_and_time.h"
#include "mbed.h"

//-----------------------------------------------------------------------------
// Defines and Macros
//-----------------------------------------------------------------------------

#define MAX_AMOUNT_OF_REGISTERS 100
#define SECONDS_IN_A_DAY 86400

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

typedef struct RainGauge {
    unsigned int accumulatedRain;
    time_t epochTime;
} RainGauge_t;

//-----------------------------------------------------------------------------
// Public Functions Prototypes
//-----------------------------------------------------------------------------

void initRainGauge(void);
void updateRainMeasure(void);
void saveRainMeasure(void);
void resetRainGauge(void);
unsigned int getAccumulatedRain(void);
bool isSameDate(void);
RainGauge_t* getAllRegistrations(void);
RainGauge_t getCurrentDayRain(void);

#endif