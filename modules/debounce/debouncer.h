#ifndef _DEBOUNCER_
#define _DEBOUNCER_

//-----------------------------------------------------------------------------
// Libraries
//-----------------------------------------------------------------------------

#include "custom_timer.h"
#include "mbed.h"

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
    Timer_t timer;
} Debouncer_t;

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------
void updateDebouncer(*Debouncer_t);
void initDebouncer(*Debouncer_t);
#endif