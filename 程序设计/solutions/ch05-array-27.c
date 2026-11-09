#include <stdio.h>

int main(void)
{
    int n, seen[1001] = {0}, x, minimum = 1001, maximum = 0, duplicate = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (seen[x]) duplicate = 1;
        seen[x] = 1;
        if (x < minimum) minimum = x;
        if (x > maximum) maximum = x;
    }
    puts(!duplicate && maximum - minimum + 1 == n ? "Yes" : "No");
    return 0;
}
