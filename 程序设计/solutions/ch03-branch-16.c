#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)
{
    long double a, b, c;
    scanf("%Lf,%Lf,%Lf", &a, &b, &c);
    if (fabsl(a) < 0.000001L) {
        puts("Not quadratic equation with one unknown!");
    } else {
        long double delta = b * b - 4 * a * c;
        long double error_bound = 4 * LDBL_EPSILON * (fabsl(b * b) + fabsl(4 * a * c));
        if (fabsl(delta) <= error_bound) delta = 0;
        if (delta == 0) {
            long double root = -b / (2 * a);
            if (root == 0) root = 0.0;
            printf("%.3Lf\n", root);
        } else if (delta < 0) {
            puts("No real roots");
        } else {
            long double x1 = (-b - sqrtl(delta)) / (2 * a);
            long double x2 = (-b + sqrtl(delta)) / (2 * a);
            if (x1 > x2) {
                long double temp = x1;
                x1 = x2;
                x2 = temp;
            }
            printf("%.3Lf,%.3Lf\n", x1, x2);
        }
    }
    return 0;
}
