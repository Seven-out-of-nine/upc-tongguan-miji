#include <stdio.h>

int main(void)
{
    int n, first[1000], second;
    const long long base = 1000000000LL;
    long long high = 0, low = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &first[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &second);
        long long product = (long long)first[i] * second;
        high += product / base;
        low += product % base;
        high += low / base;
        low %= base;
    }
    printf("%lld\n", high * base + low);
    return 0;
}
