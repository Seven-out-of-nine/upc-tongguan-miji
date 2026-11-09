#include <stdio.h>

int main(void) {
    int appeared[8] = {0}, day;
    while (scanf("%d", &day) == 1) appeared[day] = 1;
    for (int i = 1; i <= 7; ++i) if (!appeared[i]) printf("%d\n", i);
    return 0;
}
