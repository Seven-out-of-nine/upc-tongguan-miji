#include <stdio.h>
#include <string.h>
#define M 10
#define N 100

void Fun(char w[M+5][N+5], int m, int n, char a[]) {
    int k = 0;
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < m; row++) {
            a[k++] = w[row][col];
        }
    }
    a[k] = '\0';
}

int main(void) {
    int m, n;
    char w[M+5][N+5], a[M*N+1];
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) scanf("%100s", w[i]);
    Fun(w, m, n, a);
    puts(a);
    return 0;
}
