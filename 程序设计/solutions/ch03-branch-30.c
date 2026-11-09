#include <stdio.h>

int main(void)
{
    int type;
    double temperature;
    scanf("%d %lf", &type, &temperature);
    if (type == 1) {
        double centigrade = (temperature - 32) * 5.0 / 9.0;
        printf("The Centigrade is %.2f\n", centigrade);
    } else {
        double fahrenheit = temperature * 9.0 / 5.0 + 32;
        printf("The Fahrenheit is %.2f\n", fahrenheit);
    }
    return 0;
}
