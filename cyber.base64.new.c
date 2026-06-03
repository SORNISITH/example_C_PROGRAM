#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum mode {
    BASE64,
    ASCII
};

const char cb64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int base64_map[256];

int byte_t_decimal(char* byte);
void init_base64_map();
void merge_bit_ascii(char* dst, size_t dst_size, const char* str);
char* get_bit_fchar(char c);
char* decimal_t_byte(int dec);
char* read_byte_string(char* array_bit, size_t size, short mode);
char* merge_bit_base64(const char* str_base64, size_t size);
char* split_bit_base64(char* bit_array, size_t size);

char* encode_base64(const char* str);
char* decode_base64(const char* str);

int main(int argc, char* argv[])
{
    char str[] = "ABC";
    char decode[] = "bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1bDNhcm5fdGgzX3IwcDM1";

    char* encoded_str = encode_base64(str);
    char* decoded_str = decode_base64(decode);

    puts(encoded_str);
    puts(decoded_str);
    
  


    free(encoded_str);
    free(decoded_str);
    return 0;
}

char* get_bit_fchar(char c)
{
    // 000000xx001111xx1111xx000000xx00000000
    char* res = malloc(sizeof(char) * 8);
    char* ptr = res;
    for (int i = 7; i >= 0; --i, ptr++) {
        *ptr = ((c >> i) & 1) + '0'; // convert to char + '0'
    }
    *ptr = '\0'; // end of line
    return res;
}

void init_base64_map()
{
    memset(base64_map, -1, sizeof(base64_map));
    for (int i = 0; i < 64; ++i) {
        base64_map[cb64[i]] = i;
    }
}

char* get_bit_fchar(char c);

void merge_bit_ascii(char* dst, size_t dst_size, const char* str)
{
    char* proc_bit = malloc(sizeof(char) * 8);
    for (int i = 0; i < strlen(str); i++) {
        char* temp = get_bit_fchar(str[i]);
        strcat(proc_bit, temp);
    }
    char* ptr_proc_bit = proc_bit;
    size_t index = 0;
    short limit = 2;
    *dst++ = '0';
    *dst++ = '0';
    while (*ptr_proc_bit && *ptr_proc_bit != '\0') {
        if (index < 6) {
            *dst = *ptr_proc_bit;
            ++ptr_proc_bit;
            ++index;
        } else {
            *dst++ = '0';
            *dst = '0';
            index = 0;
        }
        dst++;
    }
    free(proc_bit);
}

char* decimal_t_byte(int dec)
{
    char* res = get_bit_fchar(dec);
    return res;
}

char* merge_bit_base64(const char* str_base64, size_t size)
{
    size_t len = strlen(str_base64);
    char* base64_bit_array = malloc(size); // %rax

    for (int i = 0; i < len; ++i) {
        char* temp = decimal_t_byte(base64_map[str_base64[i]]);
        strcat(base64_bit_array, temp);
    }

    return base64_bit_array;
};

int byte_t_decimal(char* byte)
{
    size_t len = strlen(byte);
    char low_byte[8] = "00000000";
    char* ptr;
    if (len < 8) {
        for (int i = 7, k = len - 1; i >= 0; --i) {
            if (k >= 0) {
                low_byte[i] = byte[k];
                k--;
            } else {
            }
        }
        ptr = low_byte + 7;
    } else {
        ptr = byte + 7;
    }
    int sum = 0;
    int base_rev = 1;
    while (*ptr && *ptr != '\0') {
        if (*ptr == '1') {
            sum += base_rev;
        };
        base_rev <<= 1;
        --ptr;
    }
    return sum;
}

char* read_byte_string(char* array_bit, size_t size, short mode)
{
    int char_count = strlen(array_bit) / 8;
    char* res = malloc(char_count);
    int index = 0;
    for (int i = 0; i < char_count; ++i) {
        char temp[8];
        for (int k = 0; k < 8; ++k) {
            if (*array_bit && *array_bit != '\0') {
                temp[k] = *array_bit;
                array_bit++;
            }
        }
        int dec = byte_t_decimal(temp);
        res[i] = (mode == BASE64) ? cb64[dec] : dec;
    }
    return res;
}

char* encode_base64(const char* str)
{
    size_t len = strlen(str);
    size_t arr_len = len * 10;
    char* bit_array = malloc(len * 10 + 1); // freed
    char* encoded_string = malloc(arr_len / 8 + 1); // %rax
    merge_bit_ascii(bit_array, arr_len, str);
    encoded_string = read_byte_string(bit_array, arr_len, BASE64);
    free(bit_array);
    return encoded_string;
}

char* split_bit_base64(char* bit_array, size_t size)
{
    char* start = bit_array + 2; // - 2 bit first
    char* res = malloc(size);
    memset(res, 0, size);
    char* ptr_res = res;
    int ele_count = 0; // limit 6 element
    while (*start && *start != '\0') {
        if (ele_count < 6) {
            *ptr_res = *start;
            ++ptr_res;
            ++ele_count;
        } else {
            ++start;
            ele_count = 0;
        }
        ++start;
    }
    return res;
}

char* decode_base64(const char* str)
{
    init_base64_map();
    size_t len = strlen(str);
    size_t size = len * 8 + 1;

    char* merged_bit = malloc(size + 1);
    merged_bit = merge_bit_base64(str, size);

    char* splited_bit = malloc(size + 1);
    splited_bit = split_bit_base64(merged_bit, size);
    char* parsed_string = read_byte_string(splited_bit, size, ASCII);

    free(merged_bit);
    free(splited_bit);
    return parsed_string;
}
