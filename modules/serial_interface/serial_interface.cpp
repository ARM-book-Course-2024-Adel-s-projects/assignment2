#include "serial_interface.h"

static void availableCommands(void);
static char receiveChar(void);
static void writeSerial(const char*);
static void configureDateAndtime(void);
static void readString(char*, int);
static void getCurrentDateAndTime(void);
static void logAllRegistrations(void);
static void logRegistration(RainGauge_t rainGauge);
static void logCurrentRegistration(void);

static UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void uartTask()
{
    char receivedChar = '\0';
    char str[100];

    receivedChar = receiveChar();
    switch (receivedChar) {
    case '1':
        sprintf ( str, "Accumulated tips: %d\r\n", getAccumulatedRain());
        writeSerial(str);
        break;
    
    case '2':
        configureDateAndtime();
        break;
    
    case '3':
        getCurrentDateAndTime();
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

static void configureDateAndtime() {
    char year[5] = "";
    char month[3] = "";
    char day[3] = "";
    char hour[3] = "";
    char minute[3] = "";
    char second[3] = "";

    writeSerial("Configuring date and time: ");
    
    writeSerial("Type 4 digits for the year (YYYY):");
    readString(year, 4);

    writeSerial("Type 2 digits for the month (MM):");
    readString(month, 2);

    writeSerial("Type 2 digits for the day (DD):");
    readString(day, 2);

    writeSerial("Type 2 digits for the hour (hh):");
    readString(hour, 2);

    writeSerial("Type 2 digits for the minute (mm):");
    readString(minute, 2);

    writeSerial("Type 2 digits for the second (ss):");
    readString(second, 2);

    setDateAndTime( atoi(year), atoi(month), atoi(day), 
        atoi(hour), atoi(minute), atoi(second) );

    writeSerial("Date and Time configured!");
}

static void availableCommands()
{
    uartUsb.write( "\n", 1);
    uartUsb.write( "Available commands:\r\n", 21 );
    uartUsb.write( "Press 'R' to get the accumulated tips of the tipping bucket raing gauge.\r\n", 48 );
}

static void readString(char* str, int strLength) {
    for(int strIndex = 0; strIndex < strLength; strIndex++) {
        uartUsb.read(&str[strIndex], 1);
    }
    str[strLength] = '\0';
}

static void getCurrentDateAndTime() {
    writeSerial(getDateAndTime());
}

static void logRegistration(RainGauge_t rainGauge) {
    writeSerial(ctime(rainGauge.epochTime));
    char str[100];

    sprintf(str, "Acumulated tips: %d", rainGauge.accumulatedRain);
    writeSerial(str);
}

static void logAllRegistrations() {
    RainGauge_t* lastRegistrations = getAllRegistrations();

    for(int i = 0; i < MAX_AMOUNT_OF_REGISTERS; i++) {
        logRegistration(lastRegistrations[i]);
    }
}

static void logCurrentRegistration() {
    RainGauge_t currentRegistration = getCurrentDayRain();
    logRegistration(currentRegistration);
}