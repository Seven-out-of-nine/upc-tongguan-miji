#include <stdio.h>

int main(void)
{
    int n, score, sum = 0, minimum = 100, maximum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &score);
        sum += score;
        if (score < minimum) minimum = score;
        if (score > maximum) maximum = score;
    }
    printf("%.2f\n", (sum - maximum - minimum) / (n - 2.0));
    return 0;
}
