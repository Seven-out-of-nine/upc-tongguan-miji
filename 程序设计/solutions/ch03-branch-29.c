#include <stdio.h>

int main(void)
{
    long long n;
    scanf("%lld", &n);
    if (n % 2 == 0) printf("%lld是偶数\n", n);
    else printf("%lld是奇数\n", n);
    return 0;
}
