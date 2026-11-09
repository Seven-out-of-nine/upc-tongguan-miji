#include <stdio.h>

int main(void)
{
    long long heads, feet;
    scanf("%lld %lld", &heads, &feet);
    long long rabbits = (feet - 2 * heads) / 2;
    long long chickens = heads - rabbits;
    printf("rabbit=%lld,chicken=%lld\n", rabbits, chickens);
    return 0;
}
