#include <stdio.h>
#include <string.h>

void Fun(double *price) {
    *price = (int)(*price / 100) * 100;
}

int main(void) {
    double price;
    scanf("%lf", &price);
    Fun(&price);
    printf("%d\n", (int)price);
    return 0;
}
