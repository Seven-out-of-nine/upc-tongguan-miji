#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int position = (n - 1) % 5;
    if (position < 3) printf("Fishing in day %d\n", n);
    else printf("Drying in day %d\n", n);
    return 0;
}
