#include "quick_sort.h"
#include <iostream>
#include "type.h"
struct Args
{
    Record *data;
    int start;
    int end;
};
void *sort_thread(void *args)
{
    Record *data = ((Args *)args)->data;
    int start = ((Args *)args)->start;
    int end = ((Args *)args)->end;
}
int sort(Record data[], int start, int end)
{
    Record tmp;
    int i = start, j = end;
    for (;;)
    {
        while (j > i)
        {
            if ((data[j].a < data[start].a) || (data[j].a == data[start].a && data[j].b < data[start].b))
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
            if ((data[i].a > data[start].a) || (data[i].a == data[start].a && data[i].b > data[start].b))
            {
                data[i].exchange(data[j]);
                break;
            }
            i++;
        }
        if (i == j)
        {
            break;
        }
    }
    data[i].exchange(data[start]);
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