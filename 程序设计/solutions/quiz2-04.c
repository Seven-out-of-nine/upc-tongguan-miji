#include <stdio.h>

int main(void) {
    int lo, hi; scanf("%d%d", &lo, &hi);
    for (int x = lo; x <= hi; ++x) {
        int left = x / 100, right = x % 100;
        int sum = left + right;
        if (sum * sum == x) printf("%d\n", x);
    }
    return 0;
}
