#ifndef _TYPE
#define _TYPE
#define ARR_LEN 1000
#include <pthread.h>
class Record
{
public:
    int a;
    int b;
    char *text;
    pthread_mutex_t lock;
    Record();
    // {
    //     pthread_mutex_init(&lock, NULL);
    //     text = new char[1024];
    // }
    void exchange(Record &new_obj);
    // {
    //     pthread_mutex_lock(&lock);
    //     pthread_mutex_init(&lock, NULL);
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
    //     pthread_mutex_unlock(&lock);
    // }
    ~Record();
    Record &operator=(Record &);
    // {
    //     pthread_mutex_destroy(&lock);
    //     delete[] text;
    // }
};
#endif