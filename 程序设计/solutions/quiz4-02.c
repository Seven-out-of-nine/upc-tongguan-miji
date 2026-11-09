#include <stdio.h>

int main(void) {
    int n, pieces = 1; scanf("%d", &n);
    for (int cut = 1; cut <= n; ++cut) pieces += cut;
    printf("%d\n", pieces); return 0;
}
