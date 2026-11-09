#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col)
            putchar(col <= row ? '1' : '0');
        putchar('\n');
    }
    return 0;
}
