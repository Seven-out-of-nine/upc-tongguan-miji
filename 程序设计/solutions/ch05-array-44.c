#include <stdio.h>

int main(void)
{
    long long matrix[4][4], multiplier;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) scanf("%lld", &matrix[i][j]);
    scanf("%lld", &multiplier);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j <= i) matrix[i][j] *= multiplier;
            printf("%4lld", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
