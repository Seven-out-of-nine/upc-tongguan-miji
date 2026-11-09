#include <stdio.h>
#include <string.h>

int main(void) {
    char a[101], b[101]; int result[202] = {0}; scanf("%100s%100s", a, b);
    int n = (int)strlen(a), m = (int)strlen(b);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[i + j] += (a[n - 1 - i] - '0') * (b[m - 1 - j] - '0');
    for (int i = 0; i < n + m; ++i) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    int top = n + m;
    while (top > 0 && result[top] == 0) --top;
    for (int i = top; i >= 0; --i) printf("%d", result[i]);
    putchar('\n'); return 0;
}
