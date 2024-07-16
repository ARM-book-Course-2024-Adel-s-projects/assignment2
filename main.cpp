#include "debouncer.h"
#include "rain_gauge.h"
#include <mbed.h>

RainGauge_t rainGauge = {
    { true, D0, UP, 0 },
    0,
    {0}
};

int main() {
    initRainGauge(&rainGauge, D0);
    while (true) {
        updateRainMeasure(&rainGauge);        
        thread_sleep_for(DELAY_TIME);
    }
}
