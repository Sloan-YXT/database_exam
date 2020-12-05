#include "csv_read.h"
#include "limits.h"
#include "type.h"
#include "radix_sort.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Record data[ARR_LEN];
int main(void)
{
    clock_t start, end;

    ifstream csv_file("../../interview/x1000.csv", ios_base::in);
    csv_file.exceptions(ios_base::badbit);
    csv_read(csv_file, data, ARR_LEN);
    start = clock();
    list<Record *> *box = radix_sort(data, ARR_LEN, 4);
    end = clock();
    csv_file.close();
    clock_t spend;
    cout << "takes " << (spend = end - start) << " time" << endl;

    cout << "total:" << ((double)spend / CLOCKS_PER_SEC) << endl;
    ofstream res("result.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < ARR_LEN; i++)
    {
        res << box->front()->a << "," << box->front()->b << "," << box->front()->text << endl;
        box->pop_front();
    }
    res.close();
}