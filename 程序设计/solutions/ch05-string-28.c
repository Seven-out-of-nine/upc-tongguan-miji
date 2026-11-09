#include <stdio.h>

int main(void) {
    char a[41], b[41]; int count[256] = {0}; scanf("%40s%40s", a, b);
    for (int i = 0; a[i]; ++i) ++count[(unsigned char)a[i]];
    for (int i = 0; b[i]; ++i) --count[(unsigned char)b[i]];
    int equal = 1;
    for (int i = 0; i < 256; ++i) if (count[i] != 0) equal = 0;
    puts(equal ? "YES" : "NO"); return 0;
}
