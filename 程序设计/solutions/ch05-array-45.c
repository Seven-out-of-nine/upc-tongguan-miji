#include <stdio.h>

int main(void)
{
    int n;
    long long matrix[100][100], value;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%lld", &matrix[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) { scanf("%lld", &value); matrix[i][j] += value; }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) putchar(' ');
            printf("%lld", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
