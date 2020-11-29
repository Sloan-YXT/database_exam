#include <fstream>
#include <iostream>
#include <pthread.h>
#include "type.h"
using namespace std;
static int thread_num = 4; //core+2
struct Params
{
    Record *data;

    int n;

    int step;

    Params(Record *data, int n, int step)
    {
        this->data = data;
        this->n = n;
        this->step = step;
    }
};

void *insert_sort(void *args)
{
    Record *data = ((Params *)args)->data;
    int n = ((Params *)args)->n;
    int step = ((Params *)args)->step;
    int i, j;
    Record watcher;
    for (j = 2 * step - 1; j < n; j += step)
    {
        watcher = data[j];
        for (i = j - step; i >= step - 1; i -= step)
        {
            if ((data[i].a < watcher.a) || (data[i].a == watcher.a && data[i].b <= watcher.b))
            {
                break;
            }
            else
            {
                data[i + step] = data[i];
            }
        }
        data[i + step] = watcher;
    }
    return nullptr;
}
void shell_sort(Record *data, int n)
{
    int step;
    pthread_t workers[thread_num];
    Params *params[thread_num];
    for (step = 1; step <= thread_num; step++)
    {
        params[step - 1] = new Params(data, n, step);
        pthread_create(&workers[step - 1], NULL, insert_sort, params);
    }
    for (int i = 0; i < thread_num; i++)
    {
        delete params[i];
    }
}
