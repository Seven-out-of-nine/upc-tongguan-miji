#include <stdio.h>

static int matrix[1000][1000];

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &matrix[i][j]);
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) putchar(' ');
            printf("%d", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
