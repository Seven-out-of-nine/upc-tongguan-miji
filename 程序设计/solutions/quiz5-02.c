#include <stdio.h>

double Fun(int *a, int *b) {
    if (*a < *b) {
        int temp = *a; *a = *b; *b = temp;
    }
    return 100.0 * (*a) / (*a + *b);
}
int main(void) {
    int a, b;
    double res = 0;
    scanf("%d%d", &a, &b);
    res = Fun(&a, &b);
    printf("%d %d %.2f", a, b, res);
    return 0;
}
