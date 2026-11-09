#include <stdio.h>

int main(void)
{
    int n, value[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) putchar(' ');
        printf("%d", value[i]);
    }
    putchar('\n');
    return 0;
}
