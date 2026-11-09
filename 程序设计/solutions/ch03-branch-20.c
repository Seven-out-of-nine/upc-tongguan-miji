#include <stdio.h>

int main(void)
{
    double score;
    scanf("%lf", &score);
    if (score < 0 || score > 100) puts("error");
    else if (score < 60) puts("D");
    else if (score < 80) puts("C");
    else if (score < 90) puts("B");
    else puts("A");
    return 0;
}
