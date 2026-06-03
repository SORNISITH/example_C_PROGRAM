#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MSG 60
#define MAX_REMAINDER 50

void add_reminder(char (*msg)[MAX_MSG], int* index);
void print_reminder(char (*msg)[MAX_MSG], int index);
int read_line_input(char* str, int n);
void get_date_input(char* date);

int main(int argc, char* argv[])
{

    char msg[MAX_REMAINDER][MAX_MSG];
    char (*ptr)[MAX_MSG] = msg;
    int index = 0;
    int option = -1;
    while (true) {
        printf("1.Add      \t=> 1\n");
        printf("2.Display  \t=> 2\n");
        printf("3.Quit     \t=> 0\n");
        printf("__________\t  : ");
        scanf("%1d", &option);
        switch (option) {
        case 1:
            add_reminder(ptr, &index);
            break;
        case 2:
            print_reminder(ptr, index);
            break;

        default:
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}

void print_reminder(char (*msg)[MAX_MSG], int index)
{
    for (int i = 0; i < index; i++) {
        printf("_ %s \n", *(msg + i));
    }
}
void add_reminder(char (*msg)[MAX_MSG], int* index)
{
    char date_str[32], msg_str[MAX_MSG + 1];
    int day = 0, num_remind = 0;
    printf("Enter Date(DD/MM/YY) and Message : ");
    get_date_input(date_str);
    read_line_input(msg_str, MAX_MSG);
    strcpy(msg[*index], strcat(date_str, msg_str));
    *index += 1;
}

void get_date_input(char* date)
{

    int day;
    int month;
    int year;
    char dash;
    scanf("%2d%c%2d%c%2d", &day, &dash, &month, &dash, &year);
    sprintf(date, "%2d%c%2d%c%2d", day, dash, month, dash, year);
}

int read_line_input(char* str, int n)
{
    int i = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        *str++ = ch;
        i++;
    }
    *(str++) = '.';
    *(str++) = '\0';
    return i;
}
