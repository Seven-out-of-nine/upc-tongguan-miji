#include <stdio.h>
#include <string.h>

void Fun(char a[], char b[], char c[]) {
    a[strcspn(a, "\r\n")] = '\0';
    b[strcspn(b, "\r\n")] = '\0';
    int na = (int)strlen(a), nb = (int)strlen(b);
    int n = na > nb ? na : nb;
    for (int i = 0; i < n; i++) {
        if (i >= na) c[i] = b[i];
        else if (i >= nb) c[i] = a[i];
        else c[i] = a[i] >= b[i] ? a[i] : b[i];
    }
    c[n] = '\0';
}

int main(void) {
    char a[1002], b[1002], c[1002];
    fgets(a, sizeof a, stdin);
    fgets(b, sizeof b, stdin);
    Fun(a, b, c);
    puts(c);
    return 0;
}
