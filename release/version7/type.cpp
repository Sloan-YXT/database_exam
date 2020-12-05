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
void Record::exchange(Record &new_obj)
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
}
Record::~Record()
{
    pthread_mutex_destroy(&lock);
    delete[] text;
}
Record &Record::operator=(Record &another)
{
    a = another.a;
    b = another.b;
    text = another.text;
    another.text = nullptr;
    return *this;
}