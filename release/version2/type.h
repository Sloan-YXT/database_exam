#ifndef _TYPE
#define _TYPE
#include <cstring>
#include <iostream>
using namespace std;
class Record
{
public:
    int a;
    int b;
    char *text;
    Record();
    // {
    //     text = new char[1024];
    // }
    Record(const Record &obj);
    // {
    //     a = obj.a;
    //     b = obj.b;
    //     text = obj.text;
    // }
    Record(Record &obj);
    // {
    //     a = obj.a;
    //     b = obj.b;
    //     memcpy(text, obj.text, 1024);
    // }
    void exchange(Record &new_obj);
    // {
    //     int a1, b1;
    //     char *tmp;
    //     a1 = a;
    //     b1 = b;
    //     tmp = text;
    //     a = new_obj.a;
    //     b = new_obj.b;
    //     text = new_obj.text;
    //     new_obj.a = a1;
    //     new_obj.b = b1;
    //     new_obj.text = tmp;
    // }
    Record &operator=(Record &new_obj);
    // {
    //     a = new_obj.a;
    //     b = new_obj.b;
    //     memcpy(text, new_obj.text, 1024);
    //     return *this;
    // }
    Record &operator=(Record &&new_obj);
    // {
    //     a = new_obj.a;
    //     b = new_obj.b;
    //     memcpy(text, new_obj.text, 1024);
    //     new_obj.text = nullptr;
    //     return *this;
    // }
    ~Record();
    // {
    //     delete[] text;
    // }
};
#endif