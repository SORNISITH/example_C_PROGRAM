#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hb[16] = {
    [1] = '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
};


char bin_to_hex(char* bin)
{
    int result = 0;
    int max_hex = 8;
    for (int i = 0; i < 4; ++i) {
        switch (bin[i]) {
        case '1':
            result += max_hex;
            break;
        case '0':
            break;
        }
        max_hex /= 2;
    }

    return hb[result];
}
char* convert_bin_hex(char* bin)
{
    size_t slen = strlen(bin);
    char* tmp_str = calloc(11, sizeof(char));
    int k = 0;
    for (int i = slen - 4; i >= 0; i -= 4) {
        tmp_str[k++] = bin_to_hex(bin + i);
    }
    tmp_str[k++] = 'x';
    tmp_str[k] = '0';

    int l = strlen(tmp_str) - 1;
    char* ps = tmp_str;
    char* pe = tmp_str + l;

    while (ps <= pe) {
        *ps ^= *pe;
        *pe ^= *ps;
        *ps ^= *pe;
        ps++, pe--;
    }
    return tmp_str;
}

int main(int argc, char* argv[])
{
    char* x = convert_bin_hex("1000110010111011");
    puts(x);
    free(x);

    for (int i = 0 ; i < 100 ; ++i) {

    }      
    

    return 0;
}
