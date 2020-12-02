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
    pthread_mutex_lock(&lock);
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
    pthread_mutex_unlock(&lock);
    return *this;
}
Record::~Record()
{
    pthread_mutex_destroy(&lock);
    delete[] text;
    text = nullptr;
}
Record &Record::operator=(const Record &another)
{
    a = another.a;
    b = another.b;
    memcpy(text, another.text, 1024);
    return *this;
}