#include <stdio.h>
#include <string.h>

int main(void) {
    char a[101], b[101]; int digits[102], n = 0;
    scanf("%100s%100s", a, b);
    int i = (int)strlen(a) - 1, j = (int)strlen(b) - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        digits[n++] = sum % 10; carry = sum / 10;
    }
    while (n > 1 && digits[n - 1] == 0) --n;
    for (int k = n - 1; k >= 0; --k) printf("%d", digits[k]);
    putchar('\n'); return 0;
}
