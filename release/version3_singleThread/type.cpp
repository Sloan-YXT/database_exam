#include <pthread.h>
#include "type.h"
#include <iostream>
#include <cstring>
using namespace std;
Record::Record()
{
    pthread_mutex_init(&lock, NULL);
    text = new char[1024];
}
Record Record::exchange(Record &new_obj)
{

    int a1, b1;
    char *tmp;
    a1 = a;
    b1 = b;
    tmp = text;
    a = new_obj.a;
    b = new_obj.b;
    text = new_obj.text;
    new_obj.a = a1;
    new_obj.b = b1;
    new_obj.text = tmp;

    return *this;
}
Record::~Record()
{
    pthread_mutex_destroy(&lock);
    if (text != nullptr)
        delete[] text;
    text = nullptr;
}
Record &Record::operator=(Record &another)
{
    // pthread_mutex_lock(&lock);
    // //lock you self first in case of dead loop
    // pthread_mutex_lock(&another.lock);
    a = another.a;
    b = another.b;
    //memcpy(text, another.text, 1024);
    text = another.text;
    another.text = nullptr;
    // pthread_mutex_unlock(&lock);
    // pthread_mutex_unlock(&another.lock);
    return *this;
}