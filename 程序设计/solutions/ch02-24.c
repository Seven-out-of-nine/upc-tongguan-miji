#include <stdio.h>

int main(void)
{
    long long seconds;
    scanf("%lld", &seconds);
    long long days = seconds / 86400;
    long long year = 2011 + days / 360;
    long long month = days % 360 / 30 + 1;
    long long day = days % 30 + 1;
    printf("%lld %lld %lld\n", year, month, day);
    return 0;
}
