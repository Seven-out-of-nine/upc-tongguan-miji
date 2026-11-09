#include <stdio.h>

int main(void) {
    int m, n, a[100][100]; scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    int equal = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
        int pixel; scanf("%d", &pixel);
        if (pixel == a[i][j]) ++equal;
    }
    printf("%.2f\n", 100.0 * equal / (m * n)); return 0;
}
