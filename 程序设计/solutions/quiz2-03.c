#include <stdio.h>

int main(void) {
    double area; int n;
    while (scanf("%lf%d", &area, &n) == 2) {
        int hundreds = (int)(area * n * 38 / 100 + 1e-9);
        printf("%d\n", hundreds * 100);
    }
    return 0;
}
