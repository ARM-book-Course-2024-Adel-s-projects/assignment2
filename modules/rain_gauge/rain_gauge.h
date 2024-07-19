//=====[Include Guards - Begin]===============================================

#ifndef _RAIN_GAUGE_
#define _RAIN_GAUGE_

//=====[Includes]=============================================================

#include "debouncer.h"
#include "date_and_time.h"
#include "mbed.h"
#include <ctime>

//=====[Macros]===============================================================

#define MAX_AMOUNT_OF_REGISTERS 100
#define SECONDS_IN_A_DAY 86400

//=====[Public Data Types]====================================================

typedef struct RainGauge {
    unsigned int accumulatedRain;
    time_t epochTime;
} RainGauge_t;

//=====[Function Declarations]================================================

void initRainGauge(void);
void updateRainMeasure(void);
void saveRainMeasure(void);
void resetRainGauge(void);
unsigned int getAccumulatedRain(void);
bool isSameDate(void);
RainGauge_t* getAllRegistrations(void);
RainGauge_t getCurrentDayRain(void);

//=====[Include Guards - End]=================================================

#endif