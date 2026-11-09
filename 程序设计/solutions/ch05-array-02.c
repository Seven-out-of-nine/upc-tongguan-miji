#include <stdio.h>
#include <string.h>

int main(void)
{
    int a, b, sum;
    char digits[16];
    scanf("%d%d", &a, &b);
    sum = a + b;
    if (sum < 0) { putchar('-'); sum = -sum; }
    sprintf(digits, "%d", sum);
    int length = (int)strlen(digits);
    for (int i = 0; i < length; ++i) {
        putchar(digits[i]);
        if (i + 1 < length && (length - i - 1) % 3 == 0) putchar(',');
    }
    putchar('\n');
    return 0;
}
