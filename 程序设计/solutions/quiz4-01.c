#include <stdio.h>

int main(void) {
    long long x, increment, n; scanf("%lld%lld%lld", &x, &increment, &n);
    long long day = x, total = 0;
    for (long long i = 0; i < n; ++i) { total += day; day += increment; }
    printf("%lld\n", total); return 0;
}
