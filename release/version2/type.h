#ifndef _TYPE
#define _TYPE
#define ARR_LEN 1000000
class Record
{
public:
    int a;
    int b;
    char *text;
    Record()
    {
        text = new char[1024];
    }
    Record exchange(Record &new_obj)
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
    ~Record()
    {
        delete[] text;
    }
};
#endif