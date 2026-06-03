#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_split_numchar(const char* str, int index, int count)
{
    char* ret = malloc(count + 1);
    for (int i = 0; i < count; ++i) {
        ret[i] = str[index++];
    }
    return ret;
}

int* splitIntoFibonacci(char* num, int* returnSize)
{
    size_t len = strlen(num);
    char tmp_arr[len];
    int cal_step = 3;
    for (int i = 0; i < 3; ++i) {
        char* x = get_split_numchar(num, i, 1);
        tmp_arr[i] = atoi(x);
        free(x);
    }
    return NULL;
}
int main(int argc, char* argv[])
{
    char* str = "123456579";
    int* xx;
    splitIntoFibonacci(str, xx);
    return 0;
}
