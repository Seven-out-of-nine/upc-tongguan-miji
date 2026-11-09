#include <stdio.h>

int Fun(int n)
{
    long long value = n;
    if (value < 0) value = -value;
    long long place = 1;
    while (value / place >= 10) place *= 10;
    long long result = 0;
    while (place > 0) {
        int digit = (int)(value / place);
        if (digit % 2 == 0) result = result * 10 + digit;
        value %= place;
        place /= 10;
    }
    return (int)result;
}

int main()
{
    int  n;
    scanf("%d",&n);
    printf("The result is: %d\n",Fun(n));
    return 0;
}
