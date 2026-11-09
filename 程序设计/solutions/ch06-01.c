#include <stdio.h>
#include <string.h>

void Fun(char s[], char t[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (i % 2 == 1 && (unsigned char)s[i] % 2 == 1) {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

int main(void) {
    char s[1001], t[1001];
    scanf("%1000s", s);
    Fun(s, t);
    puts(t);
    return 0;
}
