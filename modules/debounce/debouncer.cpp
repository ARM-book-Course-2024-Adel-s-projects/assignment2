#include "debouncer.h"

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void updateDebouncer(*Debouncer_t debouncer) {
    debouncer->isADebounce = true;
    
    switch(debouncer->currentState) {

        case UP:
            if(debouncer->input) {
                debouncer->currentState = FALLING;
                debouncer->timer_accumulator = 0;
            }
            break;
        
        case FALLING:
            if((debouncer->timer_accumulator * DELAY_TIME) >= DEBOUNCER_TIME_MS){
                debouncer->currentState = DOWN;
            } else {
                debouncer->currentState = UP;
            }
            debouncer->timer_accumulator++;
            break;
        
        case DOWN:
            if(!debouncer->input) {
                debouncer->currentState = RISING;
                debouncer->timer_accumulator = 0;
            }
            break;
        
        case RISING:
            if((debouncer->timer_accumulator * DELAY_TIME) >= DEBOUNCER_TIME_MS) {
                if(!debouncer->input) {
                    debouncer->currentState = UP;
                    debouncer->isADebounce = false;
                } else {
                    debouncer->currentState = DOWN;
                }
            }
            debouncer->timer_accumulator++;
            break;
    }
}

void initDebouncer(*Debouncer_t debouncer) {
    if(debouncer->input) {
        debouncer->currentState = UP;
    } else {
        debouncer->currentState = DOWN;
    }
}