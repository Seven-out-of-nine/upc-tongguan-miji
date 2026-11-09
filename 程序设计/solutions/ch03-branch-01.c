#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int best = a;
    if (b < best) best = b;
    printf("%d\n", best);
    return 0;
}
