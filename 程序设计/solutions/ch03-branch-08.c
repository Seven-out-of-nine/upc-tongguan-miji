#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 99999) {
        puts("Invalid input");
    } else {
        int copy = n;
        int digits = 0;
        while (copy > 0) {
            digits++;
            copy /= 10;
        }
        printf("%d\n", digits);
        while (n > 0) {
            printf("%d", n % 10);
            n /= 10;
        }
        printf("\n");
    }
    return 0;
}
