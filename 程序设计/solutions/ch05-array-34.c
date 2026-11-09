#include <stdio.h>

int main(void)
{
    int n, composite[10001] = {0}, count = 0, printed = 0;
    scanf("%d", &n);
    for (int p = 2; p <= n / p; ++p)
        if (!composite[p])
            for (int multiple = p * p; multiple <= n; multiple += p) composite[multiple] = 1;
    for (int value = 2; value <= n; ++value)
        if (!composite[value]) ++count;
    printf("%d\n", count);
    for (int value = 2; value <= n; ++value) {
        if (!composite[value]) {
            if (printed) putchar(' ');
            printf("%d", value); printed = 1;
        }
    }
    putchar('\n');
    return 0;
}
