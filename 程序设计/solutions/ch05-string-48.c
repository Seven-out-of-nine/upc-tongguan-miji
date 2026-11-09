#include <stdio.h>
#include <ctype.h>

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
    int start = 1;
    for (int i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (isspace(c)) start = 1;
        else {
            if (start && c >= 'a' && c <= 'z') s[i] = c - 'a' + 'A';
            start = 0;
        }
    }
    puts(s); return 0;
}
