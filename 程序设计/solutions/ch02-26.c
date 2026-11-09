#include <stdio.h>

int main(void)
{
    int start, end;
    scanf("%d %d", &start, &end);
    int start_minutes = start / 100 * 60 + start % 100;
    int end_minutes = end / 100 * 60 + end % 100;
    int duration = end_minutes - start_minutes;
    printf("%02d:%02d\n", duration / 60, duration % 60);
    return 0;
}
