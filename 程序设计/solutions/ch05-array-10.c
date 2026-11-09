#include <stdio.h>

int main(void)
{
    int n, price[30], day = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &price[i]);
    long long best = (long long)price[2] - price[0];
    for (int i = 1; i < n - 2; ++i) {
        long long gain = (long long)price[i + 2] - price[i];
        if (gain >= best) { best = gain; day = i; }
    }
    printf("%d\n", day + 1);
    return 0;
}
