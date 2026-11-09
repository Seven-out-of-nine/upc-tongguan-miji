#include <stdio.h>

int main(void)
{
    int n, value[100], count[101] = {0}, printed = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &value[i]); ++count[value[i]]; }
    for (int i = 0; i < n; ++i) {
        int x = value[i];
        if (count[x] > 1) {
            if (printed) putchar(' ');
            printf("%d", x); printed = 1; count[x] = 0;
        }
    }
    if (!printed) printf("Not Found");
    putchar('\n');
    return 0;
}
