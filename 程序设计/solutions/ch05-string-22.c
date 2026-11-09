#include <stdio.h>

int main(void) {
    char a[1001], b[1001]; scanf("%1000s%1000s", a, b);
    int i = 0, j = 0;
    while (a[i] && b[j]) {
        if ((unsigned char)a[i] <= (unsigned char)b[j]) putchar(a[i++]);
        else putchar(b[j++]);
    }
    while (a[i]) putchar(a[i++]);
    while (b[j]) putchar(b[j++]);
    putchar('\n'); return 0;
}
