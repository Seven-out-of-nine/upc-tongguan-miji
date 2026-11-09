#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 0) n = -n;
    int tens = n / 10;
    int ones = n % 10;
    printf("%d\n", tens + ones);
    return 0;
}
