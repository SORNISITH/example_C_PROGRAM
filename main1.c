#include <stdio.h>
typedef struct {
    int x;
    int y;
    int z;
} T_test;

T_test  myfn()
{
    T_test gogo;
    gogo.x = 10;
    gogo.y = 20;
    gogo.z = 20;
    return gogo;
}

int main()
{
    T_test zz = myfn();

    printf("%d", zz.x);
    return 0;
}

