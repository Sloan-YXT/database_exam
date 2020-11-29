#include "../release/version1/type.h"
#include "../release/version1/limits.h"
#include "../release/version1/csv_read.h"
#include "../release/version1/quick_sort.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
    Record data[ARR_LEN];
    ifstream data_file("../interview/x1.csv", ios_base::in);
    csv_read(data_file, data, ARR_LEN);
    quick_sort(data, 0, ARR_LEN - 1);
    for (int i = 0; i < ARR_LEN; i++)
    {
        cout << data[i].a << ":" << data[i].b << endl;
    }
}