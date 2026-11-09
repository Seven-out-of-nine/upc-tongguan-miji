#include <stdio.h>

int main(void)
{
    int limit, n, count[201] = {0}, price[30000];
    scanf("%d%d", &limit, &n);
    for (int i = 0; i < n; ++i) { int x; scanf("%d", &x); ++count[x]; }
    int length = 0;
    for (int x = 0; x <= limit; ++x)
        for (int k = 0; k < count[x]; ++k) price[length++] = x;
    int left = 0, right = n - 1, groups = 0;
    while (left <= right) {
        if (left < right && price[left] + price[right] <= limit) ++left;
        --right; ++groups;
    }
    printf("%d\n", groups);
    return 0;
}
