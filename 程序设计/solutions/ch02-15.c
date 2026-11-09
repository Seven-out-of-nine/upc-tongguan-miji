#include <stdio.h>

int main(void)
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    printf("中国式写法为：%d/%d/%d\n", year, month, day);
    printf("英国式写法为：%d/%d/%d\n", day, month, year);
    printf("美国式写法为：%d/%d/%d\n", month, day, year);
    return 0;
}
