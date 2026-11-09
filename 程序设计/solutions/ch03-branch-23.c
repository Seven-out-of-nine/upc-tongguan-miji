#include <stdio.h>

int main(void)
{
    int day;
    scanf("%d", &day);
    if (day == 1 || day == 3 || day == 5) puts("NO");
    else puts("YES");
    return 0;
}
