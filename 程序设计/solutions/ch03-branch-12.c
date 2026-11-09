#include <stdio.h>

int main(void)
{
    int year, month, days;
    scanf("%d %d", &year, &month);
    if (month == 2) {
        int leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
        if (leap) days = 29;
        else days = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    printf("%d\n", days);
    return 0;
}
