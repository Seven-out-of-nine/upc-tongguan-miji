#include <stdio.h>
#include <string.h>

void Fun(int *n) {
    int x = *n, result = 0, place = 1;
    while (x > 0) {
        int digit = x % 10;
        if (digit % 2 != 0) {
            result += digit * place;
            place *= 10;
        }
        x /= 10;
    }
    *n = result;
}

int main(void) {
    int n;
    scanf("%d", &n);
    Fun(&n);
    printf("%d\n", n);
    return 0;
}
