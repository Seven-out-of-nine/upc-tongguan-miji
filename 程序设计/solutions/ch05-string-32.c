#include <stdio.h>

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char s[100]; int count[26] = {0}; scanf("%99s", s);
        for (int i = 0; s[i]; ++i) ++count[s[i] - 'a'];
        int found = 0;
        for (int i = 0; s[i]; ++i) if (count[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]); found = 1; break;
        }
        if (!found) puts("NO");
    }
    return 0;
}
