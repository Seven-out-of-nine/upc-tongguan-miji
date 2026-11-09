#include <stdio.h>

int main(void)
{
    unsigned long long n;
    int count[10] = {0};
    scanf("%llu", &n);
    do { ++count[n % 10]; n /= 10; } while (n > 0);
    for (int digit = 9; digit >= 0; --digit)
        for (int i = 0; i < count[digit]; ++i) putchar('0' + digit);
    putchar('\n');
    return 0;
}
