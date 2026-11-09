#include <stdio.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int letter(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
int main(void) {
    char s[23]; read_line(s, sizeof s);
    int valid = letter(s[0]) || s[0] == '_';
    for (int i = 0; s[i]; ++i)
        if (!letter(s[i]) && !(s[i] >= '0' && s[i] <= '9') && s[i] != '_') valid = 0;
    puts(valid ? "YES" : "NO"); return 0;
}
