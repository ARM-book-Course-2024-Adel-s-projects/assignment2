//=====[Include Guards - Begin]===============================================

#ifndef _DEBOUNCER_
#define _DEBOUNCER_

//=====[Includes]=============================================================

#include "mbed.h"

//=====[Macros]===============================================================

#define DEBOUNCER_TIME_MS 50
#define DELAY_TIME 1

//=====[Public Data Types]====================================================

typedef enum {
    DOWN,
    FALLING,
    RISING,
    UP,
} state_t;

typedef struct Debouncer {
    bool isADebounce;
    DigitalIn input;
    state_t currentState;
    uint8_t timer_accumulator;
} Debouncer_t;

//=====[Function Declarations]================================================

void updateDebouncer(Debouncer_t*);
void initDebouncer(Debouncer_t*);

//=====[Include Guards - End]=================================================

#endif