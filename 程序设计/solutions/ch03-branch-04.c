#include <stdio.h>

int main(void)
{
    int start_year, start_month, start_day;
    int year, month, day;
    scanf("%d %d %d %d %d %d", &start_year, &start_month, &start_day,
          &year, &month, &day);
    int years = year - start_year;
    if (month < start_month || (month == start_month && day < start_day)) {
        years--;
    }
    printf("%d\n", years);
    return 0;
}
