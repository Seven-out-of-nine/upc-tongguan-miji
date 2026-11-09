#include <stdio.h>

int main(void)
{
    long long x, y;
    scanf("%lld", &x);
    if (x < 6) y = x - 12;
    else if (x < 15) y = 3 * x - 1;
    else y = 5 * x + 9;
    printf("%lld\n", y);
    return 0;
}
