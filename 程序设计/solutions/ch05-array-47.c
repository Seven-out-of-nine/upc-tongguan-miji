#include <stdio.h>

int main(void)
{
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n, height[50], peaks = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
        for (int i = 1; i + 1 < n; ++i)
            if (height[i] > height[i - 1] && height[i] > height[i + 1]) ++peaks;
        printf("%d\n", peaks);
    }
    return 0;
}
