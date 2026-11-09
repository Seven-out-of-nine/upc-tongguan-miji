#include <stdio.h>

long long SumInterval(int n, int m)
{
    if (n == m) return n;
    int mid = n + (int)(((long long)m - n) / 2);
    return SumInterval(n, mid) + SumInterval(mid + 1, m);
}

int GetSum(int n, int m)
{
    return (int)SumInterval(n, m);
}

int main()
{
    int m,n,s;
    scanf("%d%d",&n,&m);
    s=GetSum(n,m);
    printf("%d\n",s);
    return 0;
}
