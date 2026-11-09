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
    int t, ch; scanf("%d", &t);
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    while (t--) {
        char s[103]; read_line(s, sizeof s);
        for (int i = 0; s[i]; ++i) if (s[i] < '0' || s[i] > '9') putchar(s[i]);
        putchar('\n');
    }
    return 0;
}
