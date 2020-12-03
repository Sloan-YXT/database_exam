#include "csv_read.h"
#include "limits.h"
#include "type.h"
#include "quick_sort.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Record data[ARR_LEN];
int main(void)
{
    clock_t start, end;

    ifstream csv_file("../../interview/x100.csv", ios_base::in);
    csv_file.exceptions(ios_base::badbit);
    csv_read(csv_file, data, ARR_LEN);
    start = clock();
    quick_sort(data, 0, ARR_LEN - 1);

    end = clock();
    csv_file.close();
    clock_t spend;
    cout << "takes " << (spend = end - start) << " time" << endl;

    cout << "total:" << ((double)spend / CLOCKS_PER_SEC) << endl;
    ofstream res("result.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < ARR_LEN; i++)
    {
        if (data[i].b < 10000)
            res << data[i].a << "," << data[i].b << "," << data[i].text << endl;
    }
    res.close();
}