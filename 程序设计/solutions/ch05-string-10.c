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
    char s[1003]; read_line(s, sizeof s);
    int ch = getchar(), count = 0;
    for (int i = 0; s[i]; ++i) if (s[i] == ch) ++count;
    printf("%d\n", count); return 0;
}
