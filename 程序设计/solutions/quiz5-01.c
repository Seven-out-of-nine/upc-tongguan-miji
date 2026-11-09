#include <stdio.h>

int main(void) {
    int h1, m1, h2, m2, h3, m3, h4, m4;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    scanf("%d:%d %d:%d", &h3, &m3, &h4, &m4);
    int first = (h2 - h1) * 60 + m2 - m1;
    int second = (h4 - h3) * 60 + m4 - m3;
    if (2 * first < second) printf("Level1 %.2f\n", first / 3.0);
    else if (2 * first > second) printf("Level2 %.2f\n", second / 6.0);
    else printf("Equal %.2f\n", first / 3.0);
    return 0;
}
