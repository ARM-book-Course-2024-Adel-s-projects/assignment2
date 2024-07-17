#include "date_and_time.h"

time_t getEpochTime() {
    return time(NULL);
}

char* getDateAndTime() {
    time_t epochSeconds;
    epochSeconds = time(NULL);
    return ctime(&epochSeconds);
}

void setDateAndTime(int year, int month, int day,
                    int hour, int minute, int second) {
    
    struct tm rtcTime;

    rtcTime.tm_year = year - 1900;
    rtcTime.tm_mon  = month - 1;
    rtcTime.tm_mday = day;
    rtcTime.tm_hour = hour;
    rtcTime.tm_min  = minute;
    rtcTime.tm_sec  = second;

    rtcTime.tm_isdst = -1;

    set_time( mktime( &rtcTime ) );

}