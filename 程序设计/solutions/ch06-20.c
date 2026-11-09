#include <stdio.h>
#include <string.h>

void Fun(int a[], int n, int *odd, int *even) {
    *odd = 0;
    *even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) *even += a[i];
        else *odd += a[i];
    }
}

int main(void) {
    int n, a[1000], odd, even;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    Fun(a, n, &odd, &even);
    printf("The sum of odd numbers:%d\n", odd);
    printf("The sum of even numbers:%d\n", even);
    return 0;
}
