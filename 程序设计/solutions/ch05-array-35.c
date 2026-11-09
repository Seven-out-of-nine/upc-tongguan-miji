#include <stdio.h>

int main(void)
{
    int length, regions, removed[1001] = {0};
    scanf("%d%d", &length, &regions);
    for (int i = 0; i < regions; ++i) {
        int start, end;
        scanf("%d%d", &start, &end);
        for (int position = start; position <= end; ++position) removed[position] = 1;
    }
    int remaining = 0;
    for (int position = 0; position <= length; ++position)
        if (!removed[position]) ++remaining;
    printf("%d\n", remaining);
    return 0;
}
