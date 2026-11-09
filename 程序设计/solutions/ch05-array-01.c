#include <stdio.h>

int main(void)
{
    int n, height[1000], person, stool, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
    scanf("%d%d", &person, &stool);
    for (int i = 0; i < n; ++i)
        if (height[i] <= person + stool) ++count;
    printf("%d\n", count);
    return 0;
}
