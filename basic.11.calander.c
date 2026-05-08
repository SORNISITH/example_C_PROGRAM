#include <stdio.h>

int main(int argc, char* argv[])
{
    int d, w;
    printf("Enter number of days in month : ");
    scanf("%d", &d);
    printf("Enter starting of days of week : ");
    scanf("%d", &w);
    int calender = d + w;
    for (int i = 1, k = 1, date = 1; i <= calender; i++, k++) {
        if (i < w) {
            printf("   ");
        }
        if (i < calender && i >= w) {
            printf("%2d ", date++);
        }
        if (k == 7) {
            printf("\n");
            k = 0;
        }
    }

    return 0;
}
