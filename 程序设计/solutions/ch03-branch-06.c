#include <stdio.h>

int main(void)
{
    long long n, x, y;
    scanf("%lld %lld %lld", &n, &x, &y);
    long long damaged = y / x;
    if (y % x != 0) damaged++;
    long long whole = n - damaged;
    if (whole < 0) whole = 0;
    printf("%lld\n", whole);
    return 0;
}
