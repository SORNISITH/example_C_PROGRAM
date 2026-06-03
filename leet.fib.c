#include <stdio.h>
int fib(int n)
{
    if (n < 1)
        return 0;
    int step[n + 2];
    step[0] = 1; // default
    step[1] = 1;
    step[2] = 2;
    for (int i = 3; i <= n; ++i) {
        step[i] = step[i - 1] + step[i - 2];
    }
    return step[n];
}

int main(int argc, char* argv[])
{
    fib(5);
    return 0;
}
