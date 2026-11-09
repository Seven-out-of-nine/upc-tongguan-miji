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
    char s[83];
    read_line(s, sizeof s);
    puts(s);
    return 0;
}
