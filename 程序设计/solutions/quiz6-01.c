#include <stdio.h>

int main(void) {
    int h, m, dh, dm; scanf("%d:%d %d:%d", &h, &m, &dh, &dm);
    int minutes = ((h * 60 + m - dh * 60 - dm) % 1440 + 1440) % 1440;
    printf("%d:%02d\n", minutes / 60, minutes % 60);
    return 0;
}
