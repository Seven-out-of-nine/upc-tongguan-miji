#include <stdio.h>

static int ball[100000];

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%d", &ball[i]);
    for (int query = 0; query < n; ++query) {
        int target, left = 0, right = m - 1, found = 0;
        scanf("%d", &target);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ball[mid] == target) { found = 1; break; }
            if (ball[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        puts(found ? "YES" : "NO");
    }
    return 0;
}
