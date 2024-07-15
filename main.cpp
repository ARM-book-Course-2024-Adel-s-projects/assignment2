#include "debouncer.h"
#include "rain_gauge.h"

RainGauge_t rainGauge;

int main() {
    initRainGauge(&rainGauge);
    while (true) {
        updateRainMeasure(&rainGauge);        
        thread_sleep_for(DELAY_TIME);
    }
}
