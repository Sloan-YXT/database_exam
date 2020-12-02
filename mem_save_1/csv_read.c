#include "limits.h"
#include "type.h"
#include "csv_read.h"
//比起C++的string库，C的string库对内存消耗更低
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern int pos[ARR_LEN];
void csv_read(FILE *data_file, Record data[], int n)
{
    int i = 0;
    char tmp_buf[1200];
    while (1)
    {
        pos[i] = ftell(data_file);
        fgets(tmp_buf, 1100, data_file);
        if (tmp_buf == NULL | i == n)
        {
            break;
        }
        //cout << "debug:" << i << endl;
        char *p = strtok(tmp_buf, ",");
        data[i].a = atoi(p);
        p = strtok(NULL, ",");
        data[i].b = atoi(p);
        //strtok(NULL, "");
        data[i].index = i;
        i++;
    }
};
