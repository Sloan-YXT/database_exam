#define BITVAL(res, a, bit)           \
    {                                 \
        res = a;                      \
        for (int i = 0; i < bit; i++) \
        {                             \
            res = res / 10;           \
        }                             \
        res = res % 10;               \
    }
#include <iostream>
using namespace std;
int main(void)
{
    int a = 123456;
    int res;
    BITVAL(res, a, 1);
    cout << res << endl;
    cout << a << endl;
}