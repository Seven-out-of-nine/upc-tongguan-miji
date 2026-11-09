#include <stdio.h>

int main(void)
{
    int n, count[10] = {0};
    char number[128];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%127s", number);
        for (int j = 0; number[j] != '\0'; ++j)
            if (number[j] >= '0' && number[j] <= '9') ++count[number[j] - '0'];
    }
    int maximum = 0;
    for (int digit = 0; digit < 10; ++digit)
        if (count[digit] > maximum) maximum = count[digit];
    printf("%d\n", maximum);
    for (int digit = 0; digit < 10; ++digit)
        if (count[digit] == maximum) printf("%2d", digit);
    putchar('\n');
    return 0;
}
