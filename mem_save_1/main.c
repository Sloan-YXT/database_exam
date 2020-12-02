#include "csv_read.h"
#include "limits.h"
#include "type.h"
#include "quick_sort.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
Record data[ARR_LEN];
int pos[ARR_LEN];
#define buf_len 10
//char buffer[buf_len];
//不管用：只要有缓冲区程序就会分配一个最小空间
int main(void)
{
    clock_t start, end;
    //"../interview/x1.csv"
    FILE *csv_file = fopen("../interview/x100.csv", "r");
    setbuf(csv_file, NULL);
    // if (setvbuf(csv_file, NULL, _IOFBF, buf_len))
    // {
    //     perror("set buf error");
    //     exit(1);
    // }
    if (csv_file == NULL)
    {
        fprintf(stderr, "open file err!\n");
        exit(1);
    }
    csv_read(csv_file, data, ARR_LEN);
    start = clock();
    quick_sort(data, 0, ARR_LEN - 1);
    //fclose(csv_file);
    end = clock();
    clock_t spend;
    printf("takes %d time\n", (spend = end - start));

    printf("total: %f\n", ((double)spend / CLOCKS_PER_SEC));
    FILE *res = fopen("result.txt", "w");
    //setbuf(res, NULL);
    char tmp[1200];
    for (int i = 0; i < ARR_LEN; i++)
    {
        fseek(csv_file, pos[data[i].index], SEEK_SET);
        fgets(tmp, 1200, csv_file);
        //会读到换行符
        fprintf(res, "%s", tmp);
    }
    fclose(csv_file);
    fclose(res);
}