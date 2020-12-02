#ifndef _TYPE
#define _TYPE
typedef struct Record
{
    short a;
    short b;
    int index;
} Record;
void exchange(Record *old_obj, Record *new_obj);
#endif