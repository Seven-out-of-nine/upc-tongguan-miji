#include <stdio.h>
#include <string.h>

void Fun(char s[], int *t) {
    *t = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') (*t)++;
    }
}

int main(void) {
    char s[81];
    int t;
    fgets(s, sizeof s, stdin);
    Fun(s, &t);
    printf("%d\n", t);
    return 0;
}
