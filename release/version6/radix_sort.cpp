#include <fstream>
#include <iostream>
#include <pthread.h>
#include <list>
#include "type.h"
#include <unistd.h>
using namespace std;
//惊天大bug！
#define BITVAL(res, a, bit)                 \
    {                                       \
        res = a;                            \
        for (int __i = 0; __i < bit; __i++) \
        {                                   \
            res = res / 10;                 \
        }                                   \
        res = res % 10;                     \
    }
void show_list(list<Record> t)
{
    while (!t.empty())
    {
        auto &m = t.front();
        t.pop_front();
        cout << m.a << "," << m.b << endl;
    }
}
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
list<Record *> *radix_sort(Record a[], int len, int bits)
{
    list<Record *> nodes[10];
    list<Record *> *box = new list<Record *>();

    int res;
    for (int j = 0; j < len; j++)
    {
        BITVAL(res, a[j].b, 0);
        //cout << res << endl;
        nodes[res].push_back(&a[j]);
    }
    //sleep(5);
    // for (int j = 0; j < len; j++)
    // {
    //     show_list(nodes[j]);
    //     sleep(2);
    // }
    for (int j = 0; j < 10; j++)
    {
        while (!nodes[j].empty())
        {
            Record *tmp = nodes[j].front();
            //cout << "76" << endl;
            //在这里请格外注意容器是按值传递，而不是引用
            //为了避免析构函数被调用,只能传指针
            nodes[j].pop_front();
            //cout << "78" << endl;
            box->push_back(tmp);
        }
    }
    //show_list(*box);
    for (int i = 1; i <= bits; i++)
    {
        while (!box->empty())
        {

            Record *tmp = box->front();
            //cout << "pre:" << tmp.b << endl;
            box->pop_front();
            BITVAL(res, tmp->b, i);
            //cout << "res:" << res << endl;
            nodes[res].push_back(tmp);
            //cout << "aft:" << tmp.b << endl;
            //sleep(1);
        }
        // for (int m = 0; m < 10; m++)
        // {
        //     cout << "m:" << m << endl;
        //     show_list(nodes[m]);
        //     sleep(2);
        // }
        for (int j = 0; j < 10; j++)
        {
            while (!nodes[j].empty())
            {
                box->push_back(nodes[j].front());
                nodes[j].pop_front();
            }
        }
    }
    // show_list(*box);
    // cout << "98" << endl;
    //sleep(10);
    for (int i = 0; i <= bits; i++)
    {
        while (!box->empty())
        {
            Record *tmp = box->front();
            box->pop_front();
            BITVAL(res, tmp->a, i);
            nodes[res].push_back(tmp);
        }
        for (int j = 0; j < 10; j++)
        {
            while (!nodes[j].empty())
            {
                box->push_back(nodes[j].front());
                nodes[j].pop_front();
            }
        }
    }
    // show_list(*box);
    // cout << "118" << endl;
    return box;
}
