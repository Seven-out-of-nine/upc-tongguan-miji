#include <stdio.h>

int main(void) {
    int n, seen[256] = {0}, answer = 0; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s[101]; scanf("%100s", s);
        unsigned char first = (unsigned char)s[0];
        if (!seen[first]) { seen[first] = 1; ++answer; }
    }
    printf("%d\n", answer); return 0;
}
