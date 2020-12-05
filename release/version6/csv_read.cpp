#include <iostream>
#include <fstream>
#include "limits.h"
#include "type.h"
#include "csv_read.h"
//比起C++的string库，C的string库对内存消耗更低
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
char tmp_buf[1200];
void csv_read(ifstream &data_file, Record data[], int n)
{
    int i = 0;
    while (1)
    {
        data_file.getline(tmp_buf, 1200);
        if (data_file.eof() || i == n)
        {
            break;
        }
        //cout << "debug:" << i << endl;
        char *p = strtok(tmp_buf, ",");
        data[i].a = atoi(p);
        p = strtok(NULL, ",");
        data[i].b = atoi(p);
        p = strtok(NULL, ",");
        strcpy(data[i].text, p);
        i++;
    }
};
