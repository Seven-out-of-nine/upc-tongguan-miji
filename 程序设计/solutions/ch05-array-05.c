#include <stdio.h>

int main(void)
{
    int n, triangle[10][10] = {{0}};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; ++j)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int k = 0; k < 2 * (n - 1 - i); ++k) putchar(' ');
        for (int j = 0; j <= i; ++j) printf("%4d", triangle[i][j]);
        putchar('\n');
    }
    return 0;
}
