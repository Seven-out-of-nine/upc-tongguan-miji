#include <stdio.h>
#include <stdlib.h>

int CompareInt(const void *left, const void *right)
{
    int a = *(const int *)left, b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void)
{
    int n, x, y[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x, &y[i]);
    qsort(y, n, sizeof y[0], CompareInt);
    int median = y[n / 2];
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        long long difference = (long long)y[i] - median;
        if (difference < 0) difference = -difference;
        total += difference;
    }
    printf("%lld\n", total);
    return 0;
}
