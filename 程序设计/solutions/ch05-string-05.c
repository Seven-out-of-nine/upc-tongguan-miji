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
    char s[33]; read_line(s, sizeof s);
    int i = 0;
    while (s[i]) {
        if (s[i] < '0' || s[i] > '9') { ++i; continue; }
        int begin = i;
        while (s[i] >= '0' && s[i] <= '9') ++i;
        int end = i;
        while (begin + 1 < end && s[begin] == '0') ++begin;
        for (int j = begin; j < end; ++j) putchar(s[j]);
        putchar('\n');
    }
    return 0;
}
