#include <stdio.h>

int main(void)
{
    int n, p, value[1000];
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    for (int k = 0; k < n; ++k) {
        if (k > 0) putchar(' ');
        printf("%d", value[(p + 1 + k) % n]);
    }
    putchar('\n');
    return 0;
}
