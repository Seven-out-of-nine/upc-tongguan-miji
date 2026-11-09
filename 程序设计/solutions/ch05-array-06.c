#include <stdio.h>

int main(void)
{
    int n, value, maximum, minimum, max_id = 1, min_id = 1;
    scanf("%d%d", &n, &value);
    maximum = minimum = value;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &value);
        if (value > maximum) { maximum = value; max_id = i; }
        if (value < minimum) { minimum = value; min_id = i; }
    }
    printf("%d%d\n%d%d\n", maximum, max_id, minimum, min_id);
    return 0;
}
