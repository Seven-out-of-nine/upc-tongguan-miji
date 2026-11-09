#include <stdio.h>

int PrimeJudge(int num)
{
    if (num < 2) return 0;
    for (int d = 2; d <= num / d; ++d)
        if (num % d == 0) return 0;
    return 1;
}

int main()
{
    int num;
    scanf("%d", &num);
    if( PrimeJudge(num) )
    {
        printf("Prime\n");
    }
    else
    {
        printf("Non Prime\n");
    }
    return 0;
}
