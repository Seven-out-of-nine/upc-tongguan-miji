#include <stdio.h>

int main(void)
{
    double r;
    const double pi = 3.14;
    scanf("%lf", &r);
    double length = 2 * pi * r;
    double area = pi * r * r;
    printf("l=%.2f\ns=%.2f\n", length, area);
    return 0;
}
