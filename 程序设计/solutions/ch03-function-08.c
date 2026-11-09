#include <stdio.h>

int fun(int num)
{
    if (num < 2) return 0;
    for (int d = 2; d <= num / d; ++d)
        if (num % d == 0) return 0;
    return 1;
}

int main()
{
    int m, c, i;
    for(m = 1;; m++)
    {
        scanf("%d", &c);
        if(c == 0)  break;
        if(c % 2 == 0)
        {
            for(i = 2; i <= c - 2; i++)
            {
                if((fun(i) == 1) && (fun(c - i) == 1))
                {
                    printf("%d=%d+%d\n", c, i, c - i);
                    break;
                }
            }
        }
        if(c % 2 != 0)
        {
            printf("%d is odd number!\n", c);
        }
    }
    return 0;
}
