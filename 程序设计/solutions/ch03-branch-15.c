#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int count = n / 7 * 5;
    int remaining = n % 7;
    if (remaining > 5) remaining = 5;
    count += remaining;
    printf("%d\n", count);
    return 0;
}
