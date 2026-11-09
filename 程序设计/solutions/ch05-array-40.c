#include <stdio.h>

int main(void)
{
    int n, used[1000] = {0}, boxes = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int size, box = 0;
        scanf("%d", &size);
        while (box < boxes && used[box] + size > 100) ++box;
        if (box == boxes) ++boxes;
        used[box] += size;
        printf("%d %d\n", size, box + 1);
    }
    printf("%d\n", boxes);
    return 0;
}
