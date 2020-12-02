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
    //cout << "step" << step << endl;
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
    pthread_t workers[thread_num];
    Params *params[thread_num + 50];
    int numer = 0;
    for (int j = 10; j >= 3; j -= 3)
    {
        if (numer < thread_num)
        {
            params[numer] = new Params(data, n, j * 5);
            pthread_create(&workers[numer], NULL, insert_sort, params[numer]);
        }
        else
        {
            params[numer] = new Params(data, n, j * 5);
            insert_sort(params[numer]);
        }
        numer++;
    }
    for (int j = 8; j >= 2; j -= 3)
    {
        if (numer < thread_num)
        {
            params[numer] = new Params(data, n, j);
            pthread_create(&workers[numer], NULL, insert_sort, params[numer]);
        }
        else
        {
            params[numer] = new Params(data, n, j * 5);
            insert_sort(params[numer]);
        }
        numer++;
    }
    for (int i = 0; i < thread_num; i++)
    {
        pthread_join(workers[i], NULL);
    }
    params[numer] = new Params(data, n, 1);
    insert_sort(params[numer]);
    for (int i = 0; i <= numer; i++)
    {
        delete params[i];
    }
}
