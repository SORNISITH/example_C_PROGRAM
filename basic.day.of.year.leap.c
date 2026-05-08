#include <stdio.h>
#include <stdlib.h>

int day_off_year(int month, int day, int year);
int main(int argc, char* argv[])
{
    int x = day_off_year(1, 1, 2026);

    printf("%d", x);
    return EXIT_SUCCESS;
}

int day_off_year(int month, int day, int year)
{
    int month_count[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    printf("helllo world ");
    // check leap year
    month_count[1]
        = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;

    int total_mount_day = 0;
    for (int i = 0; i < month - 1; i++) {
        total_mount_day += month_count[i];
    }
    return total_mount_day + day;
}
