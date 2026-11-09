#include <stdio.h>

int main(void) {
    long long m, n; scanf("%lld%lld", &m, &n);
    printf("%lld %lld\n", m / n, m % n);
    return 0;
}
