#include <stdio.h>

int main(void)
{
    int m, n, value, maximum = 0, best_row = 0, best_col = 0;
    scanf("%d%d", &m, &n);
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            scanf("%d", &value);
            if ((row == 0 && col == 0) || value > maximum) {
                maximum = value; best_row = row; best_col = col;
            }
        }
    }
    printf("%d %d %d\n", maximum, best_row, best_col);
    return 0;
}
