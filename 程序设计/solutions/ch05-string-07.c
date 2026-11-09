#include <stdio.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    char s[130];
    while (fgets(s, sizeof s, stdin)) {
        int sum = 0;
        for (int i = 0; s[i]; ++i)
            if (s[i] >= 'A' && s[i] <= 'Z') sum += s[i] - 'A' + 1;
        if (sum > 100) puts("INVALID"); else printf("%d\n", sum);
    }
    return 0;
}
