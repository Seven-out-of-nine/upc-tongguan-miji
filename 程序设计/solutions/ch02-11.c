#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 0) n = -n;
    int hundreds = n / 100;
    int tens = n / 10 % 10;
    int ones = n % 10;
    printf("%d\n", hundreds + tens + ones);
    return 0;
}
