#ifndef _DEBOUNCER_
#define _DEBOUNCER_

//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "mbed.h"

//-----------------------------------------------------------------------------
// Macros and Defines
//-----------------------------------------------------------------------------

#define DEBOUNCER_TIME_MS 50
#define DELAY_TIME 1

//-----------------------------------------------------------------------------
// Public types
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------
void updateDebouncer(*Debouncer_t);
void initDebouncer(*Debouncer_t);
#endif