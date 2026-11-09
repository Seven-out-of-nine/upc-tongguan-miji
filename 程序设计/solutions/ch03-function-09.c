#include <stdio.h>

double GetSum(int n)
{
    double sum = 1.0, term = 1.0;
    for (int i = 1; i <= n; ++i) {
        term /= i;
        sum += term;
    }
    return sum;
}

int main()
{
   int  n;
   double  s;
   scanf("%d",&n);
   s=GetSum(n);
   printf("s=%f\n",s);
   return 0;
}
