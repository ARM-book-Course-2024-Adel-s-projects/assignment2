#include "serial_interface.h"

static void availableCommands(void);

static UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void uartTask(RainGauge_t rainGauge)
{
    char receivedChar = '\0';
    char str[100];
    int stringLength;
    if( uartUsb.readable() ) {
        uartUsb.read( &receivedChar, 1 );
        switch (receivedChar) {
        case 'R':
            uartUsb.write( "\n", 1);
            sprintf ( str, "Accumulated tips: %.2f\r\n", rainGauge.accumulatedRain);
            stringLength = strlen(str);
            uartUsb.write( str, stringLength);

        default:
            availableCommands();
            break;

        }
    }
}

static void availableCommands()
{
    uartUsb.write( "Available commands:\r\n", 21 );
    uartUsb.write( "Press 'R' to get the accumulated tips of the tipping bucket raing gauge.\r\n", 48 );
}