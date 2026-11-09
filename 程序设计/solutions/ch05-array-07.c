#include <stdio.h>

int main(void)
{
    int score[10], maximum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &score[i]);
        if (score[i] > maximum) maximum = score[i];
    }
    for (int i = 0; i < 10; ++i)
        if (score[i] == maximum) printf("%d\n", i);
    return 0;
}
