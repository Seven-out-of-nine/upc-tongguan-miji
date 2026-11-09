#include <stdio.h>
#include <string.h>

void Fun(int a[], int n, int *k) {
    *k = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[*k]) *k = i;
    }
}

int main(void) {
    int a[10], k;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    Fun(a, 10, &k);
    printf("%d,%d\n", k, a[k]);
    return 0;
}
