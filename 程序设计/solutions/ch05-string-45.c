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
    char s[85]; read_line(s, sizeof s);
    int n = 0; while (s[n]) ++n;
    if (n > 0) {
        char first = s[0];
        for (int i = 0; i + 1 < n; ++i) s[i] = s[i + 1];
        s[n - 1] = first;
    }
    puts(s); return 0;
}
