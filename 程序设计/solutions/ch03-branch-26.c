#include <stdio.h>

int main(void)
{
    long long shirts, trousers;
    scanf("%lld %lld", &shirts, &trousers);
    long long suits = shirts;
    if (trousers < suits) suits = trousers;
    long long suit_price = 90;
    if (suits >= 50) suit_price = 80;
    long long cost = suits * suit_price + (shirts - suits) * 60
                   + (trousers - suits) * 45;
    printf("%lld\n", cost);
    return 0;
}
