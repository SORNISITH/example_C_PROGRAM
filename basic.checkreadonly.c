#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char* lit = "hello";
    char arr[] = "world";
    char* heap = malloc(10);
    printf("PID : %d", getpid());
    printf("literal: %p\n", lit);
    printf("array:   %p\n", arr);
    printf("heap:    %p\n", heap);

    getchar(); // pause
    return 0;
}
