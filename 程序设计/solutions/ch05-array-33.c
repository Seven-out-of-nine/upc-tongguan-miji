#include <stdio.h>

int main(void)
{
    int n, reader, count[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &reader);
        ++count[reader];
        if (i) putchar(' ');
        printf("%d", count[reader]);
    }
    putchar('\n');
    return 0;
}
