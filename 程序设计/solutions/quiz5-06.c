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
    char s[23]; read_line(s, sizeof s);
    int upper = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') upper = 1;
        if (s[i] == ' ') s[i] = '0';
    }
    if (!upper) s[0] = s[0] - 'a' + 'A';
    puts(s); return 0;
}
