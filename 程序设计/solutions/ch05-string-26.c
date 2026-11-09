#include <stdio.h>
#include <string.h>

int main(void) {
    int n; char a[99][101]; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%100s", a[i]);
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) if (strcmp(a[i], a[j]) == 0) ++count;
        if (count == 1) { puts(a[i]); break; }
    }
    return 0;
}
