#include <stdio.h>

int main(void)
{
    long long one_yuan, five_jiao, one_jiao;
    scanf("%lld %lld %lld", &one_yuan, &five_jiao, &one_jiao);
    long long cents = one_yuan * 100 + five_jiao * 50 + one_jiao * 10;
    printf("Dollars=%lld\nChange=%lld\n", cents / 100, cents % 100);
    return 0;
}
