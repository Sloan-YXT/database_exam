#include "type.h"
//把类函数定义在外部文件大大节省了代码段空间
//定义在类内:33k
//定义在另一文件:20k
Record::Record()
{
    text = new char[1024];
}
Record::Record(const Record &obj)
{
    a = obj.a;
    b = obj.b;
    text = obj.text;
}
Record::Record(Record &obj)
{
    a = obj.a;
    b = obj.b;
    memcpy(text, obj.text, 1024);
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
Record &Record::operator=(Record &new_obj)
{
    a = new_obj.a;
    b = new_obj.b;
    memcpy(text, new_obj.text, 1024);
    return *this;
}
Record &Record::operator=(Record &&new_obj)
{
    a = new_obj.a;
    b = new_obj.b;
    memcpy(text, new_obj.text, 1024);
    new_obj.text = nullptr;
    return *this;
}
Record::~Record()
{
    delete[] text;
};