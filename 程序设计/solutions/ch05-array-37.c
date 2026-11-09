#include <stdio.h>

static int value[1000000];

int FindPosition(int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (value[mid] == target) return mid;
        if (value[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void)
{
    int n, queries;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    scanf("%d", &queries);
    while (queries--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int distance = FindPosition(n, a) - FindPosition(n, b);
        if (distance < 0) distance = -distance;
        printf("%d\n", distance);
    }
    return 0;
}
