#include <stdio.h>

int main(void)
{
    long long km, cost;
    scanf("%lld", &km);
    if (km <= 3) cost = 10;
    else if (km <= 10) cost = 10 + (km - 3) * 2;
    else cost = 10 + 7 * 2 + (km - 10) * 3;
    printf("%lld\n", cost);
    return 0;
}
