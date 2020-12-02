#include "quick_sort.h"
#include "type.h"
#define EVAL(record) (record.a * 100000 + record.b)
int sort(Record data[], int start, int end)
{
    int i = start, j = end;
    // Record tmp;
    for (;;)
    {
        while (j > i)
        {
            if (EVAL(data[j]) < EVAL(data[start]))
            {
                break;
            }
            j--;
        }
        if (i == j)
        {
            break;
        }
        while (i < j)
        {
            if (EVAL(data[i]) > EVAL(data[start]))
            {
                exchange(&data[i], &data[j]);
                // tmp = data[j];
                // data[j] = data[i];
                // data[i] = tmp;
                break;
            }
            i++;
        }
        if (i == j)
        {
            break;
        }
    }
    // tmp = data[start];
    // data[start] = data[i];
    // data[i] = tmp;
    exchange(&data[i], &data[start]);
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