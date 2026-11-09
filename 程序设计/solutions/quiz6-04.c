#include <stdio.h>

double FunCount(int a[], int n, int *max, int *min) {
    int sum = 0;
    *max = *min = a[0];
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] < a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
    return (double)sum / n;
}
int main(void) {
    int n,i,max,min;
    double avg;
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n; i ++) scanf("%d",&a[i]);
    avg = FunCount(a,n,&max,&min);
    printf("%.2f %d %d\n",avg,max,min);
    for (i = 0; i < n; i ++) printf("%d ",a[i]);
    putchar('\n');
    return 0;
}
