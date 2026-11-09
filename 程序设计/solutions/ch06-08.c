#include <stdio.h>
#include <string.h>

void Fun(char s[], char ch) {
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ch) s[k++] = s[i];
    }
    s[k] = '\0';
}

int main(void) {
    char s[1002], ch;
    fgets(s, sizeof s, stdin);
    s[strcspn(s, "\r\n")] = '\0';
    scanf("%c", &ch);
    Fun(s, ch);
    puts(s);
    return 0;
}
