#include <stdio.h>
#include <string.h>

void Fun(char s[]) {
    char temp[1001];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') temp[j++] = s[i];
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') temp[j++] = s[i];
    }
    temp[j] = '\0';
    strcpy(s, temp);
}

int main(void) {
    char s[1001];
    scanf("%1000s", s);
    Fun(s);
    puts(s);
    return 0;
}
