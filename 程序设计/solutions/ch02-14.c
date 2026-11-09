#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    unsigned int u = (unsigned int)x;
    printf("x=%d,x=%o,x=%x\n", x, u, u);
    return 0;
}
