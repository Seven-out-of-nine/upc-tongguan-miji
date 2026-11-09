#include <stdio.h>

int main(void)
{
    double t;
    scanf("%lf", &t);
    double temperature = 4 * t * t / (t + 2) - 20;
    printf("%.2f\n", temperature);
    return 0;
}
