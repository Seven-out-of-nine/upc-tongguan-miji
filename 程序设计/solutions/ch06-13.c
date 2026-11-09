#include <stdio.h>
#include <string.h>

void Fun(int a, int b, int *c) {
    *c = (a % 10) * 1000 + (b % 10) * 100 + (a / 10) * 10 + b / 10;
}

int main(void) {
    int a, b, c;
    scanf("%d,%d", &a, &b);
    Fun(a, b, &c);
    printf("%d\n", c);
    return 0;
}
