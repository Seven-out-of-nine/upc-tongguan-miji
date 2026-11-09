#include <stdio.h>

double fun(double x, int n)
{
    double sum = 1.0, term = 1.0;
    for (int i = 1; i <= n; ++i) {
        term = term * x / i;
        sum += term;
    }
    return sum;
}

int main()
{
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    printf("%f\n",fun(x,n));
    return 0;
}
