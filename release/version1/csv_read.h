#ifndef _CSV_READ
#define _CSV_READ
#include <fstream>
#include "type.h"
using namespace std;
int csv_read(ifstream &data_file, Record data[], int n);
#endif