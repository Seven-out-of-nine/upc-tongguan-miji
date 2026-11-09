#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int answer = 0;
        for (int divisor = 2; divisor <= n / divisor; ++divisor) {
            while (n % divisor == 0) { ++answer; n /= divisor; }
        }
        if (n > 1) ++answer;
        printf("%d\n", answer);
    }
    return 0;
}
