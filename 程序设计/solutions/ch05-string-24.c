#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101], t[101]; scanf("%100s%100s", s, t);
    int result = strcmp(s, t);
    if (result > 0) puts("s>t"); else if (result < 0) puts("s<t"); else puts("s=t");
    return 0;
}
