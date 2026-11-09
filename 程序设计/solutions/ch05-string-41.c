#include <stdio.h>

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char s[300]; scanf("%299s", s);
        int g = 0, l = 0, b = 0;
        for (int i = 0; s[i]; ++i) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
            if (c == 'G') g = 1;
            if (c == 'L') l = 1;
            if (c == 'B') b = 1;
        }
        puts(g && l && b ? "YES" : "NO");
    }
    return 0;
}
