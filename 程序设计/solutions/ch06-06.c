#include <stdio.h>
#include <string.h>

int Fun(char s[]) {
    int i = 0, sign = 1, value = 0;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') sign = -1;
        i++;
    }
    for (; s[i] != '\0'; i++) value = value * 10 + s[i] - '0';
    return sign * value;
}

int main(void) {
    char s[10];
    scanf("%9s", s);
    printf("%d\n", Fun(s));
    return 0;
}
