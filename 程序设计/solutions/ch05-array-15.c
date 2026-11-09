#include <stdio.h>

int main(void)
{
    int n, height, minimum = 1000;
    long long total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &height);
            total += height;
            if ((i == j || i + j == n - 1) && height < minimum) minimum = height;
        }
    }
    long long retained = (2LL * n - 1) * minimum;
    printf("%lld\n", (total - retained) * 2);
    return 0;
}
