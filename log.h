#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#define DEBUG(format, arg...)do{\
        FILE *stdclear;\
        FILE *stdsize=fopen("./explode.log","r");\
        fseek(stdsize,0,SEEK_END);\
        int size = ftell(stdsize);\
        if(size>=408000){\
        stdclear = fopen("./explode.log","w");fclose(stdclear);}\
        FILE *stdlog = fopen("./explode.log", "a+");\
        if (NULL != stdlog){\
        char DATE[25] = {0};\
        time_t timep;\
        time(&timep);\
        struct tm *p;\
        p = gmtime(&timep);\
        snprintf(DATE, 25, "[%d-%d-%d %s]", 1900 + p->tm_year, p->tm_mon + 1, p->tm_mday , __TIME__);\
        fprintf(stdlog, "%s[file:%s,function:%s,line:%d] ", DATE, __FILE__, __FUNCTION__, __LINE__);\
        fprintf(stdlog, format, ##arg);\
        fprintf(stdlog, "\n");\
        fclose(stdlog);\
        fclose(stdsize);\
        }} while(0)
