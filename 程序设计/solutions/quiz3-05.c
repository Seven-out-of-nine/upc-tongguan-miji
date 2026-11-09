#include <stdio.h>

int main(void) {
    int count[1000] = {0}, id, maximum = 0;
    while (scanf("%d", &id) == 1 && id >= 0) {
        ++count[id]; if (count[id] > maximum) maximum = count[id];
    }
    int first = 1;
    if (maximum > 0) for (int i = 0; i < 1000; ++i) if (count[i] == maximum) {
        if (!first) putchar(' '); printf("%d", i); first = 0;
    }
    putchar('\n'); return 0;
}
