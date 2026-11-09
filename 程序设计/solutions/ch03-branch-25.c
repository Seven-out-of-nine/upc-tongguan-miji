#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int maximum = m;
    if (n > maximum) maximum = n;
    printf("max=%d\n", maximum);
    return 0;
}
