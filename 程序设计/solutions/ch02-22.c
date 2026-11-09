#include <stdio.h>

int main(void)
{
    double speed_kmh, distance;
    scanf("%lf %lf", &speed_kmh, &distance);
    double speed = speed_kmh / 3.6;
    double acceleration = speed * speed / (2 * distance);
    printf("%.2f\n", acceleration);
    return 0;
}
