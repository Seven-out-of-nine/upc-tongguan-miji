#include <stdio.h>

int main(void)
{
    int id[70], score[70], sorted[70], n = 0, number, mark;
    while (scanf("%d%d", &number, &mark) == 2) {
        if (number < 0 || mark < 0) break;
        id[n] = number; score[n] = sorted[n] = mark; ++n;
    }
    int target;
    scanf("%d", &target);
    for (int i = 1; i < n; ++i) {
        int key = sorted[i], j = i - 1;
        while (j >= 0 && sorted[j] < key) { sorted[j + 1] = sorted[j]; --j; }
        sorted[j + 1] = key;
    }
    for (int i = 0; i < n; ++i) { if (i) putchar(' '); printf("%d", sorted[i]); }
    putchar('\n');
    for (int i = 0; i < n; ++i)
        if (id[i] == target) { printf("%d %d\n", id[i], score[i]); return 0; }
    puts("not find!");
    return 0;
}
