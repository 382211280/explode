#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include <sqlite3.h>
#include <string.h>
int get_table_cb(void *para, int col, char **col_value, char **col_name)
{
    for (int i = 0; i < col; i++)
    {
        DEBUG("name:[%s]:value[%s]", col_name[i], col_value[i]);
    }
    return 0;
}
int sqlite3_main()
{
    sqlite3 *db;
    int res;
    char *errmsg = NULL;
    char **dbResult;
    int raw, col;
    res = sqlite3_open("./ex_cfg.db", &db);
    if (res != SQLITE_OK)
    {
        fprintf(stderr, "db open error.\n");
        return -1;
    }
    // res = sqlite3_get_table(db, "select * from tb_ex_cfg;", &dbResult, &raw, &col, &errmsg);
    // if (res == SQLITE_OK)
    // {
    //     int index = 0;
    //     int len = 0;
    //     DEBUG("Find %d datas\n", raw);
    //     char line[1000] = {0};
    //     for (int i = 0; i <raw; i++)
    //     {
    //         DEBUG("%d data", i);
    //         for (int j = 0; j < col; j++)
    //         {
    //             len += snprintf(line + len, 100, dbResult[i * index + j]);
    //             len += snprintf(line + len, 2, "\t");
    //             ++index;
    //         }
    //         DEBUG("%s", line);
    //         DEBUG("%s", "----------------------------------------");
    //     }
    // }
    // else
    // {
    //     fprintf(stderr, "get table error:%s \n", errmsg);
    // }
    // sqlite3_free_table(dbResult);
    const char *data;
    const char *emsg;
    sqlite3_stmt *smt = NULL;
    res = sqlite3_prepare_v2(db, "select * from tb_ex_cfg;", -1, &smt, &emsg);
    if (res == SQLITE_OK)
    {
        int len = 0;
        int8_t str_result[100] = {0};
        while (sqlite3_step(smt) == SQLITE_ROW)
        {
            for (int k = 0; k < col; k++)
            {
                data = (const char *)sqlite3_column_text(smt, k);
                len += snprintf(str_result + len, 15, "|\t%s\t|", data);
            }
            DEBUG("%s", str_result);
        }
    }
    else
    {
        fprintf(stderr, "db open error: %s", emsg);
        return -1;
    }

    res = sqlite3_exec(db, "SELECT * FROM tb_ex_cfg LIMIT ((SELECT count(version) FROM tb_ex_cfg)-1),1;",
                       get_table_cb, NULL, &errmsg);

    sqlite3_finalize(smt);
    sqlite3_close(db);
    return 0;
}