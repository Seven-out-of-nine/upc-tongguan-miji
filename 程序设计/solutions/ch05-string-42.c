#include <stdio.h>

int main(void) {
    char s[14]; scanf("%13s", s);
    int sum = 0, weight = 1;
    for (int i = 0; i < 12; ++i) if (s[i] != '-') sum += (s[i] - '0') * weight++;
    int remainder = sum % 11;
    char expected = remainder == 10 ? 'X' : '0' + remainder;
    if (s[12] == expected) puts("Right");
    else { s[12] = expected; puts(s); }
    return 0;
}
