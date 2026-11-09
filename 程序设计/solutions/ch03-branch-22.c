#include <stdio.h>

int main(void)
{
    double weight, height;
    scanf("%lf %lf", &weight, &height);
    double index = weight / (height * height);
    if (index < 18) puts("di");
    else if (index <= 25) puts("zheng");
    else if (index <= 27) puts("chao");
    else puts("pang");
    return 0;
}
