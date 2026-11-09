#include <stdio.h>

int main(void)
{
    int year;
    scanf("%d", &year);
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        puts("yes");
    } else {
        puts("no");
    }
    return 0;
}
