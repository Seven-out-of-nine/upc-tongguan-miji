#include <stdio.h>

int MergeData(int num1, int num2)
{
    int a = num1 / 10, b = num1 % 10;
    int c = num2 / 10, d = num2 % 10;
    return b * 1000 + d * 100 + a * 10 + c;
}

int main()
{
    int num1, num2, newnum;
    scanf("%d%d", &num1, &num2);
    newnum = MergeData(num1, num2);
    printf("newnum=%d\n", newnum);
    return 0;
}
