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
    char s[83]; read_line(s, sizeof s);
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; s[i]; ++i) if (i < n - 1 || i >= n - 1 + m) putchar(s[i]);
    putchar('\n'); return 0;
}
