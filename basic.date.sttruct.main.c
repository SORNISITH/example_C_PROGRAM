#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct fmt {
    unsigned int days : 5;
    unsigned int months : 4;
    unsigned int years : 23;
};

typedef union Date {
    unsigned int code;
    struct fmt fmt;
} Date;

char* month[] = { [1] = "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Oct", "Sep", "Nov", "Dec" };

void split_date(char* d);


int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Need Argument!");
        return EXIT_FAILURE;
    }
    char x[2];
    int d, m, y;
    Date* new_input_date = malloc(sizeof(Date));
    sscanf(argv[1], "%d %c %d %c %d", &d, x, &m, x, &y);
    new_input_date->fmt.days = d;
    new_input_date->fmt.months = (m > 12 && m >= 1) ? 1 : m;
    new_input_date->fmt.years = y;

    printf("%zu", LONG_MAX);
    printf("%s , %d , %d\n", month[new_input_date->fmt.months], new_input_date->fmt.days, new_input_date->fmt.years);
    printf("%d", new_input_date->code);
    free(new_input_date);
    return EXIT_SUCCESS;
}
