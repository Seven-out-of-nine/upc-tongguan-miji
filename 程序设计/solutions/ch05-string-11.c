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
    char s[1003]; int count[10] = {0}; read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i)
        if (s[i] >= '0' && s[i] <= '9') ++count[s[i] - '0'];
    for (int d = 0; d < 10; ++d) if (count[d]) printf("%d:%d\n", d, count[d]);
    return 0;
}
