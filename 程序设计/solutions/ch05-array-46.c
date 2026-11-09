#include <stdio.h>

int DigitValue(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

long long Convert(const char text[], int base)
{
    long long value = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        int digit = DigitValue(text[i]);
        if (digit >= base || value > (1000000000LL - digit) / base) return -1;
        value = value * base + digit;
    }
    return value;
}

int main(void)
{
    char m[65], n[65];
    scanf("%64s%64s", m, n);
    for (int base_m = 2; base_m <= 36; ++base_m) {
        long long a = Convert(m, base_m);
        if (a < 0) continue;
        for (int base_n = 2; base_n <= 36; ++base_n) {
            long long b = Convert(n, base_n);
            if (b >= 0 && a == b) {
                printf("%s (base %d) = %s (base %d)\n", m, base_m, n, base_n);
                return 0;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n", m, n);
    return 0;
}
