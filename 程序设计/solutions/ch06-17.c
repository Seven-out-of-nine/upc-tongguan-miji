#include <stdio.h>
#include <string.h>

void Fun(int a[], int p, int n) {
    int temp[80], k = 0;
    for (int i = p + 1; i < n; i++) temp[k++] = a[i];
    for (int i = 0; i <= p; i++) temp[k++] = a[i];
    for (int i = 0; i < n; i++) a[i] = temp[i];
}

int main(void) {
    int a[80] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int p, n = 15;
    scanf("%d", &p);
    Fun(a, p, n);
    for (int i = 0; i < n; i++) printf("%3d", a[i]);
    printf("\n");
    return 0;
}
