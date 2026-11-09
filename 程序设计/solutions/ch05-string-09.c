#include <stdio.h>
#include <string.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    int t; scanf("%d", &t);
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
    while (t--) {
        char s[103]; read_line(s, sizeof s);
        int i = 0;
        while (s[i]) {
            while (s[i] == ' ') ++i;
            int start = i;
            char word[103]; int n = 0;
            while (s[i] && s[i] != ' ') {
                char c = s[i++];
                word[n++] = c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
            }
            word[n] = '\0';
            if (n >= 3 && strcmp(word,"and") && strcmp(word,"for") && strcmp(word,"the")) {
                char c = s[start];
                putchar(c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c);
            }
        }
        putchar('\n');
    }
    return 0;
}
