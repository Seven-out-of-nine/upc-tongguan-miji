#include <stdio.h>

int Deposit(int day)
{
    int total = 0, daily = 1;
    for (int i = 1; i <= day; ++i) {
        total += daily;
        if (i < day) daily *= 2;
    }
    return total;
}

int Withdraw(int day, int amount)
{
    return day * amount;
}

int main()
{
    int n,i,day;
    int amount,dpt,wd;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&amount);
        for(day=1;; day++)
        {
            dpt=Deposit(day);
            wd=Withdraw(day,amount);
            if(dpt-wd>0)
            {
                printf("%d天骗取现金%d元\n",day,dpt-wd);
                break;
            }
        }
    }
    return 0;
}
