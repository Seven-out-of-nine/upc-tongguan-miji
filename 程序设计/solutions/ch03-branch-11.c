#include <stdio.h>

int main(void)
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        puts("non-triangle");
    } else if (a == b && b == c) {
        puts("equilateral triangle");
    } else if (a == b || a == c || b == c) {
        puts("isoceles triangle");
    } else {
        puts("triangle");
    }
    return 0;
}
