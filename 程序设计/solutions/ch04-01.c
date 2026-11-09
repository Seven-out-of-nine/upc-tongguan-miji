#include <stdio.h>
int main(void) {
    long long m, n;
    scanf("%lld%lld", &m, &n);
    long long a = m, b = n;
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    long long gcd = a;
    long long lcm = (m / gcd) * n;
    printf("the greatest common divisor is %lld\n", gcd);
    printf("the least common multiple is %lld\n", lcm);
    return 0;
}
