#include "serial_interface.h"

static void availableCommands(void);
static char receiveChar(void);
static void writeSerial(const char*);

static UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void uartTask()
{
    char receivedChar = '\0';
    char str[100];

    uartUsb.read( &receivedChar, 1 );
    switch (receivedChar) {
    case 'R':
        sprintf ( str, "Accumulated tips: %d\r\n", getAccumulatedRain());
        writeSerial(str);
        break;

    case '\0':
        break;

    default:
        availableCommands();
        break;

    }
    
}

static void writeSerial(const char* message) {
    int stringLength;
    uartUsb.write("\n", 1);
    stringLength = strlen(message);
    uartUsb.write(message, stringLength);
}

static char receiveChar() {
    char receivedChar = '\0';
    if(uartUsb.readable()) {
        uartUsb.read(&receivedChar, 1);
    }
    return receivedChar;
}

static void availableCommands()
{
    uartUsb.write( "\n", 1);
    uartUsb.write( "Available commands:\r\n", 21 );
    uartUsb.write( "Press 'R' to get the accumulated tips of the tipping bucket raing gauge.\r\n", 48 );
}