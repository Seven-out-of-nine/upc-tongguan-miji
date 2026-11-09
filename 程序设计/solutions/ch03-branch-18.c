#include <stdio.h>

int main(void)
{
    double a, b, c, temp;
    scanf("%lf,%lf,%lf", &a, &b, &c);
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    printf("%.1f,%.1f,%.1f\n", a, b, c);
    return 0;
}
