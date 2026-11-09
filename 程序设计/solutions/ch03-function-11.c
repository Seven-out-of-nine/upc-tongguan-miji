#include <stdio.h>

int Gcd(int n, int m)
{
    if (m == 0) return n;
    return Gcd(m, n % m);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",Gcd(n,m));
    return 0;
}
