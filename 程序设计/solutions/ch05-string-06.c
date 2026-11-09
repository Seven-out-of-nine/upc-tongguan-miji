#include <stdio.h>

int value(const char s[]) {
    int result = 1;
    for (int i = 0; s[i]; ++i) result = result * (s[i] - 'A' + 1) % 47;
    return result;
}
int main(void) {
    char a[7], b[7]; scanf("%6s%6s", a, b);
    puts(value(a) == value(b) ? "GO" : "STAY");
    return 0;
}
