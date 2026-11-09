#include <stdio.h>

int main(void)
{
    double value;
    scanf("%lf", &value);
    if (value < 0) value = -value;
    if (value == 0) value = 0.0;
    printf("%.6f\n", value);
    return 0;
}
