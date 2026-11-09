#include <stdio.h>
#include <string.h>

void Fun(char str[], char sub[], int *count) {
    str[strcspn(str, "\r\n")] = '\0';
    sub[strcspn(sub, "\r\n")] = '\0';
    int n = (int)strlen(str), m = (int)strlen(sub);
    *count = 0;
    if (m == 0) return;
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && str[i+j] == sub[j]) j++;
        if (j == m) (*count)++;
    }
}

int main(void) {
    char s[1002], sub[1002];
    int count;
    fgets(s, sizeof s, stdin);
    fgets(sub, sizeof sub, stdin);
    Fun(s, sub, &count);
    printf("%d\n", count);
    return 0;
}
