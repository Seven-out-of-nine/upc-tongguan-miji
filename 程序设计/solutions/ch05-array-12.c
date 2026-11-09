#include <stdio.h>

int main(void)
{
    int n, m, value;
    long long sum = 0;
    scanf("%d%d", &n, &m);
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            scanf("%d", &value);
            if (row == 0 || row == n - 1 || col == 0 || col == m - 1) sum += value;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
