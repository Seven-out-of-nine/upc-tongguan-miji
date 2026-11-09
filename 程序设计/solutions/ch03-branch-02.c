#include <stdio.h>

int main(void)
{
    long long x, y;
    scanf("%lld", &x);
    if (x < 6) {
        y = 6 * x - 4;
    } else if (x < 15) {
        y = 9 * x - 5;
    } else {
        y = 15 * x - 5;
    }
    printf("%lld\n", y);
    return 0;
}
