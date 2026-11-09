#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b) {
        puts("C");
    } else if (a == c) {
        puts("B");
    } else {
        puts("A");
    }
    return 0;
}
