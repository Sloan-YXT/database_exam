#include "quick_sort.h"
#include <iostream>
#include "type.h"
#include "pthread.h"
//static pthread_t thread1, thread2;
static pthread_t thread1;
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
    quick_sort(data, start, end);
    return NULL;
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
static int first_shoot = true;
void quick_sort(Record data[], int start, int end)
{
    if (start >= end)
        return;
    int mid = sort(data, start, end);
    if (first_shoot)
    {
        Args arg1;
        arg1.data = data;
        arg1.start = start;
        arg1.end = mid - 1;
        // arg2.data = data;
        // arg2.start = mid + 1;
        // arg2.end = end;
        first_shoot = false;
        pthread_create(&thread1, NULL, sort_thread, &arg1);
        //pthread_create(&thread2, NULL, sort_thread, &arg2);
        quick_sort(data, mid + 1, end);
        pthread_join(thread1, NULL);
    }
    else
    {
        quick_sort(data, start, mid - 1);
        quick_sort(data, mid + 1, end);
    }
}