#include <stdio.h>

int main(void)
{
    double length, width, height, weight;
    scanf("%lf %lf %lf %lf", &length, &width, &height, &weight);
    if (length <= 0 || length > 1 || width <= 0 || width > 1 ||
        height <= 0 || height > 1 || weight <= 0 || weight > 30) {
        puts("error");
    } else {
        double rate;
        if (weight < 10) rate = 0.8;
        else if (weight < 20) rate = 0.75;
        else rate = 0.7;
        printf("%.2f\n", weight * rate + 0.2);
    }
    return 0;
}
