#include <stdio.h>

int main(void)
{
    int n, target, value[20], position = -1;
    scanf("%d%d", &n, &target);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    for (int i = 0; i < n; ++i) {
        if (value[i] == target) { position = i; break; }
    }
    if (position == -1) puts("Not Found");
    else printf("%d\n", position);
    return 0;
}
