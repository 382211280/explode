#include <stdio.h>
#include <stdlib.h>

#include "cmd.h"

void version_cmd(int argc, char *argv[])
{
    int ch;
    char SOFT_NAME[] = "explode";
    char VERSION[] = "0.0.2";
    while ((ch = getopt(argc, argv, "V") != -1))
    {
        switch (ch)
        {
        case 'V':
            printf("%s:%s\n", SOFT_NAME, VERSION);
            break;
        }
    }
}