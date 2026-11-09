#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 1000 || n > 9999) {
        puts("Invalid data");
    } else {
        int sum = n / 1000 + n / 100 % 10 + n / 10 % 10 + n % 10;
        if (sum % 2 == 0) puts("yes");
        else puts("no");
    }
    return 0;
}
