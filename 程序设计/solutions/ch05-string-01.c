#include <stdio.h>

int main(void) {
    char s[81];
    if (scanf("%80s", s) == 1) puts(s);
    return 0;
}
