#include <stdio.h>

int main(void) {
    int n, change[25] = {0}; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int start, end; scanf("%d%d", &start, &end);
        ++change[start]; --change[end];
    }
    int active = 0, answer = 0;
    for (int hour = 0; hour < 24; ++hour) {
        active += change[hour];
        if (active > answer) answer = active;
    }
    printf("%d\n", answer); return 0;
}
