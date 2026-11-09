#include <stdio.h>
#include <string.h>

int Prime(int x) {
    if (x < 2) return 0;
    for (int d = 2; d <= x / d; d++) {
        if (x % d == 0) return 0;
    }
    return 1;
}

int main(void) {
    int m, k, count = 0, primes[1000];
    scanf("%d%d", &m, &k);
    for (int x = m + 1; count < k; x++) {
        if (Prime(x)) primes[count++] = x;
    }
    for (int i = 0; i < k; i++) printf("%s%d", i ? " " : "", primes[i]);
    printf("\n");
    return 0;
}
