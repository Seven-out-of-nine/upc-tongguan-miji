#include <stdio.h>

int main(void)
{
    int value[10];
    for (int i = 0; i < 10; ++i) scanf("%d", &value[i]);
    for (int i = 0; i < 10; ++i) {
        int rank = 1;
        for (int j = 0; j < 10; ++j)
            if (value[j] < value[i]) ++rank;
        printf("%3d", rank);
    }
    putchar('\n');
    return 0;
}
