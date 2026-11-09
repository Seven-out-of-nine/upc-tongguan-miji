#include <stdio.h>

int main(void)
{
    int n, height[1001], newcomer;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
    scanf("%d", &newcomer);
    int position = n;
    while (position > 0 && height[position - 1] > newcomer) {
        height[position] = height[position - 1];
        --position;
    }
    height[position] = newcomer;
    for (int i = 0; i <= n; ++i) {
        if (i) putchar(' ');
        printf("%d", height[i]);
    }
    putchar('\n');
    return 0;
}
