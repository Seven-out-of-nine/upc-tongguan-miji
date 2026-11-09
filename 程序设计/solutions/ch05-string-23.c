#include <stdio.h>

int main(void) {
    char a[101], b[101], c; scanf("%100s%100s %c", a, b, &c);
    int inserted = 0;
    for (int i = 0; a[i]; ++i) {
        if (!inserted && a[i] == c) { printf("%s", b); inserted = 1; }
        putchar(a[i]);
    }
    putchar('\n'); return 0;
}
