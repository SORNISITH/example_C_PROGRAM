#include <stdio.h>

int gcd_cal(int m, int n);
int main(int argc, char* argv[])
{
    int m, n;
    char buf;

    printf("Enter fraction : ");
    scanf("%d%c%d", &m, &buf, &n);
    int gcd = gcd_cal(m, n);
    m = m / gcd;
    n = n / gcd;
    printf("gcd_cal %d\n", gcd);
    printf("lower term : %d%c%d", m, buf, n);
    return 0;
}
int euclid_gcd(int u, int v)
{
    if (u < v) {
        u ^= v;
        v ^= u;
        u ^= v;
    } // swwwup make sure a > v
    int temp;

    while ((temp = u % v) > 0) {
        u = v;
        v = temp;
    }
    return v;
}

int gcd_cal(int m, int n)
{
    int temp;
    while (n > 0) {
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
