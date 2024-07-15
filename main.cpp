#include "debouncer.h"
#include "rain_gauge.h"

#define REED_SWITCH_INPUT 0

void initReedSwitch();

Debouncer_t reedSwitch;
RainGauge_t rainGauge;

int main() {
    initReedSwitch();
    while (true) {
        updateDebouncer(&reedSwitch);
        if(!reedSwitch->isADebounce) {
            rainGauge.updateRainMeasure();
        }
        thread_sleep_for(DELAY_TIME);
    }
}

void initReedSwitch() {
    reedSwitch.input = DigitalIn(REED_SWITCH_INPUT);
    initDebouncer(&reedSwitch);
}