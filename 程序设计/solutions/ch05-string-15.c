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
    int n, ch; scanf("%d", &n);
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    while (n--) {
        char s[83]; read_line(s, sizeof s);
        int kinds[4] = {0}, len = 0;
        while (s[len]) {
            char c = s[len++];
            if (c >= '0' && c <= '9') kinds[0] = 1;
            else if (c >= 'A' && c <= 'Z') kinds[1] = 1;
            else if (c >= 'a' && c <= 'z') kinds[2] = 1;
            else kinds[3] = 1;
        }
        int total = kinds[0] + kinds[1] + kinds[2] + kinds[3];
        if (len < 6 || total <= 1) puts("Not Safe");
        else if (total == 2) puts("Medium Safe"); else puts("Safe");
    }
    return 0;
}
