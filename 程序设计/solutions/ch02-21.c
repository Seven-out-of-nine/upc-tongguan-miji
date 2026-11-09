#include <stdio.h>

int main(void)
{
    double distance, speed, km_per_liter, price;
    scanf("%lf %lf %lf %lf", &distance, &speed, &km_per_liter, &price);
    double hours = distance / speed;
    double cost = distance / km_per_liter * price;
    printf("%.1f %.1f\n", hours, cost);
    return 0;
}
