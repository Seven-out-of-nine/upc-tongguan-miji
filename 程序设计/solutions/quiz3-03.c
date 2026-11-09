#include <stdio.h>

int main(void) {
    char s[31];
    while (scanf("%30s", s) == 1) {
        for (int i = 0; s[i]; ++i) if (s[i] == '6') printf("zan!");
        putchar('\n');
    }
    return 0;
}
