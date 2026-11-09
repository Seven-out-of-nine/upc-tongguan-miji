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
    char s[83]; int count[26] = {0}, height = 0;
    read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i) if (s[i] >= 'A' && s[i] <= 'Z') ++count[s[i] - 'A'];
    for (int i = 0; i < 26; ++i) if (count[i] > height) height = count[i];
    for (int row = height; row >= 1; --row) {
        for (int col = 0; col < 26; ++col) {
            if (col) putchar(' ');
            putchar(count[col] >= row ? '*' : ' ');
        }
        putchar('\n');
    }
    for (int col = 0; col < 26; ++col) { if (col) putchar(' '); putchar('A' + col); }
    putchar('\n'); return 0;
}
