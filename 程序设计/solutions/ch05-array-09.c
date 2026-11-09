#include <stdio.h>

int main(void)
{
    int n, height[50], sum = 0, moves = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &height[i]); sum += height[i]; }
    int average = sum / n;
    for (int i = 0; i < n; ++i)
        if (height[i] > average) moves += height[i] - average;
    printf("The minimum number is %d.\n", moves);
    return 0;
}
