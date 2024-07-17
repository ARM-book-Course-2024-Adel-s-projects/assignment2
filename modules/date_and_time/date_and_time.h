#ifndef _DATE_AND_TIME_
#define _DATE_AND_TIME_

#include "mbed.h"

time_t getEpochTime(void);
char* getDateAndTime(void);
void setDateAndTime(int year, int month, int day,
                    int hour, int minute, int second);

#endif