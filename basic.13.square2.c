#include <limits.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
    long i, n;
    printf("THIS print square ");
    printf("Enter Number of Table : ");
    scanf("%ld", &n);
    int k;
    
    char x;
    for (i = 1, k = 1; i <= n; i++, k++) {
        if (k < 24) {
            printf("%10ld%10ld\n", i, i * i);
        } else if (k >= 24) {
            k = 0;
            printf("Press Any key to continue ................");
            while (getchar() != '\n')
                ;
        }
    }
    return 0;
}
