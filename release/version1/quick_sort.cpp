#include "quick_sort.h"
#include <iostream>
#include "type.h"
#define EVAL(record) (record.a * 100000 + record.b)
int sort(Record data[], int start, int end)
{
    Record standard = data[start];
    Record tmp;
    int i = start, j = end;
    for (;;)
    {
        while (j > i)
        {
            if (EVAL(data[j]) < EVAL(standard))
            {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
                break;
            }
            j--;
        }
        if (i == j)
        {
            tmp = data[i];
            data[i] = standard;
            data[start] = tmp;
            break;
        }
        while (i < j)
        {
            if (EVAL(data[i]) > EVAL(standard))
            {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
                break;
            }
            i++;
        }
        if (i == j)
        {
            break;
        }
    }
    return i;
}
void quick_sort(Record data[], int start, int end)
{
    if (start >= end)
        return;
    int mid = sort(data, start, end);
    quick_sort(data, start, mid - 1);
    quick_sort(data, mid + 1, end);
}