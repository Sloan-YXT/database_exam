#include <fstream>
#include <iostream>
#include <pthread.h>
#include "type.h"
using namespace std;
Record b[ARR_LEN];
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
inline void merge(Record a[], int m, int n, int p)
{
    //Record *b = new Record[p - m + 1];
    int i = m, j = n;
    int pos = 0;
    for (;;)
    {
        for (; i < n; i++)
        {
            if (compare(a[i], a[j]) > 0)
            {
                break;
            }
            b[pos++] = a[i];
        }
        if (i == n)
        {
            break;
        }
        for (; j <= p; j++)
        {
            if (compare(a[i], a[j]) < 0)
            {
                break;
            }
            b[pos++] = a[j];
        }
        if (j == p + 1)
        {
            break;
        }
    }
    while (i < n)
        b[pos++] = a[i++];
    while (j <= p)
        b[pos++] = a[j++];
    for (int k = 0; k < pos; k++)
    {
        a[m + k] = b[k];
    }
    //delete[] b;
}
void merge_sort(Record a[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(a, start, mid);
    merge_sort(a, mid + 1, end);
    merge(a, start, mid + 1, end);
}