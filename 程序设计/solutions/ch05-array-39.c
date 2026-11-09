#include <stdio.h>

int main(void)
{
    int first[4001] = {0}, total = 0;
    for (int number = 1; number < 10000; ++number) {
        int value = number, ones = 0;
        while (value > 0) { if (value % 10 == 1) ++ones; value /= 10; }
        while (ones-- > 0) first[++total] = number;
    }
    int tests, target;
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &target);
        if (target <= total) printf("%d\n", first[target]);
        else puts("zzz");
    }
    return 0;
}
