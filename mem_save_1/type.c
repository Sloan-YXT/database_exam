#include "type.h"
//把类函数定义在外部文件大大节省了代码段空间
//定义在类内:33k
//定义在另一文件:20k
// Record::Record()
// {
// }
// Record::Record(const Record &obj)
// {
//     a = obj.a;
//     b = obj.b;
//     index = obj.index;
// }
// Record::Record(Record &obj)
// {
//     a = obj.a;
//     b = obj.b;
//     index = obj.index;
// }
void exchange(Record *old_obj, Record *new_obj)
{
    int a1, b1;
    int tmp;
    a1 = old_obj->a;
    b1 = old_obj->b;
    tmp = old_obj->index;
    old_obj->a = new_obj->a;
    old_obj->b = new_obj->b;
    old_obj->index = new_obj->index;
    new_obj->a = a1;
    new_obj->b = b1;
    new_obj->index = tmp;
}
// Record &Record::operator=(Record &new_obj)
// {
//     a = new_obj.a;
//     b = new_obj.b;
//     index = new_obj.index;
//     return *this;
// }

// Record::~Record(){

// };