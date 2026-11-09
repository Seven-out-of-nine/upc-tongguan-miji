#include <stdio.h>

int main(void)
{
    int n, m, score;
    long long row_sum[30] = {0}, col_sum[10] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &score);
            row_sum[i] += score; col_sum[j] += score;
        }
    }
    for (int j = 0; j < m; ++j) printf(" %.2f", (double)col_sum[j] / n);
    putchar('\n');
    for (int i = 0; i < n; ++i) printf("%lld\n", row_sum[i]);
    return 0;
}
