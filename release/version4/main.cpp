#include "csv_read.h"
#include "limits.h"
#include "type.h"
#include "quick_sort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
Record data[ARR_LEN];
int main(void)
{
    clock_t start, end;
    start = clock();
    ifstream csv_file("../../interview/x100.csv", ios_base::in);
    csv_file.exceptions(ios_base::badbit);
    csv_read(csv_file, data, ARR_LEN);
    quick_sort(data, 0, ARR_LEN - 1);
    csv_file.close();
    end = clock();
    clock_t spend;
    cout << "takes " << (spend = end - start) << " time" << endl;

    cout << "total:" << ((double)spend / CLOCKS_PER_SEC) << endl;
    ofstream res("result.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < ARR_LEN; i++)
    {
        res << data[i].a << "," << data[i].b << endl;
    }
    res.close();
    sleep(5);
    //see how much memory we consume;
}