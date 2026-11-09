#include <stdio.h>

int main(void)
{
    int year, weekday, days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d", &year, &weekday);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) days[1] = 29;
    for (int month = 0; month < 12; ++month) {
        if ((weekday + 12) % 7 == 5) printf("%d/%d/13\n", year, month + 1);
        weekday = (weekday + days[month]) % 7;
    }
    return 0;
}
