#include <stdio.h>

int main(void) {
    int cases; scanf("%d", &cases);
    while (cases--) {
        int t; char s[1001]; scanf("%d%1000s", &t, s);
        int i = 0;
        while (i < t) {
            int j = i + 1;
            while (j < t && s[j] == s[i]) ++j;
            printf("%d%c", j - i, s[i]);
            i = j;
        }
        putchar('\n');
    }
    return 0;
}
