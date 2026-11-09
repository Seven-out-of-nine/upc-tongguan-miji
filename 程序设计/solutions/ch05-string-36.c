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
    char s[103], sub[103]; read_line(s, sizeof s); read_line(sub, sizeof sub);
    int n = 0, m = 0, answer = -1;
    while (s[n]) ++n;
    while (sub[m]) ++m;
    for (int start = 0; start + m <= n; ++start) {
        int j = 0;
        while (j < m && s[start + j] == sub[j]) ++j;
        if (j == m) { answer = start; break; }
    }
    printf("%d\n", answer); return 0;
}
