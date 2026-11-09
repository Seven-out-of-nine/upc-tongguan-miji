#include <stdio.h>

int main(void)
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld/%lld=%lld\n", a, b, a / b);
    printf("%lld%%%lld=%lld\n", a, b, a % b);
    return 0;
}
