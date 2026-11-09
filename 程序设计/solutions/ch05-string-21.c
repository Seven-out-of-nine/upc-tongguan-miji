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
    char a[103], b[103], result[201];
    read_line(a, sizeof a); read_line(b, sizeof b);
    int k = 0;
    for (int i = 0; a[i]; ++i) result[k++] = a[i];
    for (int i = 0; b[i]; ++i) result[k++] = b[i];
    result[k] = '\0'; puts(result); return 0;
}
