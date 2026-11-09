#include <stdio.h>

int main(void)
{
    int n, m, matrix[10][10];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &matrix[i][j]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ok = 1;
            for (int k = 0; k < m; ++k)
                if (matrix[i][k] > matrix[i][j]) ok = 0;
            for (int k = 0; k < n; ++k)
                if (matrix[k][j] < matrix[i][j]) ok = 0;
            if (ok) { printf("a[%d][%d]=%d\n", i, j, matrix[i][j]); return 0; }
        }
    }
    puts("Not Found");
    return 0;
}
