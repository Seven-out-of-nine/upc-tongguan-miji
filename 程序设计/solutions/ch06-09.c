#include <stdio.h>
#include <string.h>

void Fun(char s[]) {
    s[strcspn(s, "\r\n")] = '\0';
    int n = (int)strlen(s);
    if (n <= 1) return;
    char first = s[0];
    for (int i = 0; i < n - 1; i++) s[i] = s[i+1];
    s[n-1] = first;
}

int main(void) {
    char s[82];
    fgets(s, sizeof s, stdin);
    Fun(s);
    puts(s);
    return 0;
}
