#include <fstream>
#include <iostream>
#include <pthread.h>
#include "type.h"
using namespace std;
#define EVAL(record) (record.a * 100000 + record.b)
inline int compare(Record &a, Record &b)
{
    if (a.a < b.a)
    {
        return -1;
    }
    else if (a.a == b.a)
    {
        if (a.b < b.b)
        {
            return -1;
        }
        else if (a.b == b.b)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
void sift(Record data[], int start, int end)
{
    if (start == end)
        return;
    //for efficency
    int r = start;
    int k = (r + 1) * 2 - 1;
    while (k <= end)
    {
        if (k + 1 <= end && compare(data[k], data[k + 1]) > 0)
        {
            k = k + 1;
        }
        if (compare(data[k], data[r]) < 0)
        {
            data[r].exchange(data[k]);
        }
        else
        {
            break;
        }
        r = k;
        k = (r + 1) * 2 - 1;
    }
}
void heap_sort(Record data[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        sift(data, i, len - 1);
    }
    for (int j = len - 1; j > 0; j--)
    {
        data[0].exchange(data[j]);
        sift(data, 0, j - 1);
    }
}