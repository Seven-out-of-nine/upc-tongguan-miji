#include <stdio.h>

int main(void)
{
    int hour, minute;
    scanf("%d %d", &hour, &minute);
    double angle = 5.5 * minute - 30 * (hour % 12);
    if (angle < 0) angle = -angle;
    if (angle > 180) angle = 360 - angle;
    printf("At %d:%02d the angle is %.1f degrees.\n", hour, minute, angle);
    return 0;
}
