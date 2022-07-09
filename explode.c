/*
 * @LastEditors: zhaodejin
 * @Description: Copyright by zhaodejin
 */
// 标准库
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// 应用拓展库
#include <sqlite3.h>
// 自定义封装
#include "list.h"
#include "hashmap.h"
#include "log.h"
#include "sqlite.h"
#include "cmd.h"
#include "ex_event.h"
#include "ex_time.h" //这个头文件必须添加，不然stdsoap2.cpp文件里会报一个引用错误。要移植到项目中去还需要注意：这个头文件必须放到源文件中，不能放到头文件中。具体为什么我一时还不懂。
int main(int argc, char *argv[])
{
    DEBUG("size_t = %d", sizeof(size_t));
    DEBUG("uint64_t = %d", sizeof(uint64_t));
    DEBUG("uint16_t = %d", sizeof(uint16_t));
    DEBUG("uint8_t = %d", sizeof(uint8_t));
    DEBUG("uint32_t = %d", sizeof(uint32_t));
    DEBUG("int  = %d", sizeof(int));
    DEBUG("long = %d", sizeof(long));
    DEBUG("char = %d", sizeof(char));
    DEBUG("float = %d", sizeof(float));
    DEBUG("long long  = %d", sizeof(long long));

    llink g_head = NULL;
    int a[] = {1, 23, 23, 43};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        insert_list(&g_head, a[i]);
    }
    print_list(g_head);
    destroy_list(g_head);
    sqlite3_main();
    hashmap_main();
    DEBUG("%s", get_cur_time());
    DEBUG("cpu个数目:%d",sysconf(_SC_NPROCESSORS_CONF));
    DEBUG("可用cpu个数:%d",sysconf(_SC_NPROCESSORS_ONLN));
    event_main();
    version_cmd(argc, argv);
    return 0;
}