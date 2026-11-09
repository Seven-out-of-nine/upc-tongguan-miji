#include <stdio.h>
#include <string.h>

int main(void) {
    int n; char cities[100][41], target[41]; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%40s", cities[i]);
    scanf("%40s", target);
    int count = 0;
    for (int i = 0; i < n; ++i) if (strcmp(cities[i], target) == 0) ++count;
    printf("%d\n", count); return 0;
}
