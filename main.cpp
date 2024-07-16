#include "debouncer.h"
#include "rain_gauge.h"
#include "serial_interface.h"
#include <mbed.h>

DigitalIn PIN_1(D0);

RainGauge_t rainGauge = {
    { true, PIN_1, UP, 0 },
    0,
    {0}
};

int main() {
    PIN_1.mode(PullUp);
    initRainGauge(&rainGauge);
    while (true) {
        updateRainMeasure(&rainGauge);
        uartTask(rainGauge);   
        thread_sleep_for(DELAY_TIME);
    }
}
