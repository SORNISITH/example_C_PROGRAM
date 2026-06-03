#include <complex.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void isbn(void);
void magic_square();
int main(int argc, char* argv[])
{
    magic_square();
    return 0;
}

void magic_square()
{
    char array_number_input[100];
    int array_number[16];
    printf("Enter 1 - 16 any Order :");
    fgets(array_number_input, 100, stdin);
    int i, next_i, j, new_index;
    next_i = i + 1;
    i = new_index = next_i = 0;
    printf("%s\n", array_number_input);
    printf("%d ", array_number_input[i]);
    while (array_number_input[i] != '\0') {
        if (array_number_input[i] != ' ' && array_number_input[i + 1] == ' ') {

            int x = array_number_input[i];
            array_number[new_index] = atoi(x);
        }

        // if (array_number_input[i] != ' ' && array_number_input[i + 1] != ' ') {
        //       char get_2_digit_number[2];
        //     get_2_digit_number[0] = array_number_input[i];
        //     get_2_digit_number[1] = array_number_input[i + 1];
        //     int x = atoi(get_2_digit_number);
        //     array_number[new_index] = x;
        //     new_index++;
        // }
        // i++;
    }

    // printf("%s\n", array_number_input);
    // for (int i = 0; i >= 16; i++) {
    //     printf("%d", array_number[i]);
    // }
}
void isbn(void)
{
    printf("ENTER ISBN : ");
    int gs_prefix, group_id, publish_code, item_number, check_digit = 0;
    char dash;
    scanf("%d%c%d%c%d%c%d%c%d", &gs_prefix, &dash, &group_id, &dash, &publish_code, &dash, &item_number, &dash, &check_digit);
    printf("GS1 Prefix \t:%d\n", gs_prefix);
    printf("Group ID \t:%d\n", group_id);
    printf("Publish Code \t:%d\n", publish_code);
    printf("Items Number \t:%d\n", item_number);
    printf("Check Digit \t:%d\n", check_digit);
}
