#include <stdio.h>

int main(void) {
    long long number;
    while (scanf("%lld", &number) == 1) {
        if (number < 0) number = -number;
        int count = 0;
        do {
            int digit = number % 10;
            if (digit % 2 == 0) ++count;
            number /= 10;
        } while (number > 0);
        printf("%d\n", count);
    }
    return 0;
}
