#include <stdio.h>

int main(void)
{
    int n, height[1000], answer[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
    for (int i = 0; i < n - 1; ++i) {
        int best = i;
        for (int j = i + 1; j < n; ++j)
            if (height[j] > height[best]) best = j;
        int temp = height[i]; height[i] = height[best]; height[best] = temp;
    }
    int middle = n / 2;
    answer[middle] = height[0];
    for (int i = 1; i < n; ++i) {
        int distance = (i + 1) / 2;
        int position = (i % 2 == 1) ? middle + distance : middle - distance;
        answer[position] = height[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", answer[i]);
    }
    putchar('\n');
    return 0;
}
