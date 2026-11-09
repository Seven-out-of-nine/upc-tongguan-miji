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
    char s[83], digits[83]; int n = 0;
    read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i)
        if (s[i] >= '0' && s[i] <= '9') digits[n++] = s[i];
    digits[n] = '\0';
    int first = 0;
    while (first < n && digits[first] == '0') ++first;
    if (first == n) puts("0"); else puts(digits + first);
    return 0;
}
