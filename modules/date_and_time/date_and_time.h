//=====[Include Guards - Begin]===============================================

#ifndef _DATE_AND_TIME_
#define _DATE_AND_TIME_

//=====[Includes]=============================================================

#include "mbed.h"

//=====[Public Data Types]====================================================

typedef struct DateTime {
    int year;
    int day;
    int month;
    int hour;
    int minute;
    int second;
} DateTime_t;

//=====[Function Declarations]================================================

time_t getEpochTime(void);
char* getDateAndTime(void);
void setDateAndTime(int year, int month, int day,
                    int hour, int minute, int second);
DateTime_t getDateTimeFromEpoch(time_t epoch);

//=====[Include Guards - End]=================================================

#endif