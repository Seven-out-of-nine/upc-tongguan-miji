#include <stdio.h>

int main(void)
{
    int n, off[101] = {0}, count = 0;
    scanf("%d", &n);
    for (int step = 1; step <= n; ++step)
        for (int lamp = step; lamp <= n; lamp += step) off[lamp] = !off[lamp];
    for (int lamp = 1; lamp <= n; ++lamp)
        if (off[lamp]) ++count;
    printf("%d\n", count);
    for (int lamp = 1; lamp <= n; ++lamp)
        if (off[lamp]) printf("%4d", lamp);
    putchar('\n');
    return 0;
}
