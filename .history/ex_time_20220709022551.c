#include <time.h>
#include <stdio.h>
#include "ex_time.h"
char str_time[TIME_LEN];

char *get_cur_time()
{
    time_t timep;
    time(&timep);
    struct tm *p;
    p = gmtime(&timep);
    snprintf(str_time, 25, "[%d-%d-%d %s]", 1900 + p->tm_year, p->tm_mon + 1, p->tm_mday, __TIME__);
    return str_time;
}
