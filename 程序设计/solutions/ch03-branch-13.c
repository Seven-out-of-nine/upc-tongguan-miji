#include <stdio.h>

int main(void)
{
    long long transmitters, receivers;
    scanf("%lld %lld", &transmitters, &receivers);
    long long pairs = transmitters;
    if (receivers < pairs) pairs = receivers;
    long long price = 900;
    if (pairs >= 50) price = 800;
    long long cost = pairs * price + (transmitters - pairs) * 600
                   + (receivers - pairs) * 450;
    printf("%lld\n", cost);
    return 0;
}
