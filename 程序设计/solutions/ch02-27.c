#include <stdio.h>

int main(void)
{
    long long n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);
    long long rows = (n + a - 1) / a;
    long long columns = (m + a - 1) / a;
    printf("%lld\n", rows * columns);
    return 0;
}
