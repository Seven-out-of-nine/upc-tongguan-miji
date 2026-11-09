#include <stdio.h>
#include <string.h>

void Fun(char s[]) {
    int n = (int)strlen(s), last = n - 1;
    while (last >= 0 && s[last] == '*') last--;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '*' || i > last) s[k++] = s[i];
    }
    s[k] = '\0';
}

int main(void) {
    char s[1001];
    scanf("%1000s", s);
    Fun(s);
    puts(s);
    return 0;
}
