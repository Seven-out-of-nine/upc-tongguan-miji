#include <stdio.h>

int main(void)
{
    int start_hour, start_minute, end_hour, end_minute, errors;
    scanf("%d:%d %d:%d %d", &start_hour, &start_minute,
          &end_hour, &end_minute, &errors);
    int start = start_hour * 60 + start_minute;
    int end = end_hour * 60 + end_minute;
    int penalty = end - start + 20 * errors;
    printf("%d\n", penalty);
    return 0;
}
