/*
 * @Author: zhaodejin 382211280@qq.com
 * @Date: 2022-07-09 00:35:12
 * @LastEditors: zhaodejin 382211280@qq.com
 * @LastEditTime: 2022-07-09 12:51:26
 * @FilePath: /explode/ex_time.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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