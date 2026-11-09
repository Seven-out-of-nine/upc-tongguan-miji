#include <stdio.h>

double Facto(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

int main()
{
	int n,i;
	double result = 1;
	scanf("%d",&n);
	if(n<=0)
	{
	    printf("Input data error!\n");
	}
	else
	{
	    for(i = 1;i <= n; i++)
	    {
	        result = Facto(i);
	        printf("%d!=%.0f\n",i,result);
	    }
	}
	return 0;
}
