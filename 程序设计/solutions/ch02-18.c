#include <stdio.h>

int main(void)
{
    double first, second;
    int number;
    char ch;
    scanf("%lf %d %c %lf", &first, &number, &ch, &second);
    printf("%c %d %.2f %.2f\n", ch, number, first, second);
    return 0;
}
