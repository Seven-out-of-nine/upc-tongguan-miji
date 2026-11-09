#include <stdio.h>

int main(void) {
    int count[1000] = {0}, train, maximum = 0;
    while (scanf("%d", &train) == 1 && train != 0) {
        ++count[train]; if (count[train] > maximum) maximum = count[train];
    }
    int first = 1;
    if (maximum) for (int i = 1; i <= 999; ++i) if (count[i] == maximum) {
        if (!first) putchar(' '); printf("G%03d", i); first = 0;
    }
    putchar('\n'); return 0;
}
