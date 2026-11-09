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
    char s[103];
    while (fgets(s, sizeof s, stdin)) {
        int n = 0; while (s[n] && s[n] != '\n' && s[n] != '\r') ++n;
        s[n] = '\0';
        while (n > 0 && n % 2 == 0) {
            int symmetric = 1;
            for (int i = 0; i < n / 2; ++i) if (s[i] != s[n - 1 - i]) symmetric = 0;
            if (!symmetric) break;
            n /= 2; s[n] = '\0';
        }
        puts(s);
    }
    return 0;
}
