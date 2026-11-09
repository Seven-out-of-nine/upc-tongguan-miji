#include <stdio.h>
#include <string.h>

void Fun(int x, int aa[], int *n) {
    *n = 0;
    for (long long d = 1; d <= x; d += 2) {
        if (x % d == 0) aa[(*n)++] = (int)d;
    }
}

int main(void) {
    int x, aa[1000], n;
    scanf("%d", &x);
    Fun(x, aa, &n);
    for (int i = 0; i < n; i++) printf(" %d", aa[i]);
    printf("\n");
    return 0;
}
