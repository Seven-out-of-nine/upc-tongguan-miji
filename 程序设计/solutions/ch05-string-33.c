#include <stdio.h>
#include <string.h>

int main(void) {
    int m, n; char all[50][21], present[50][21]; scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%20s", all[i]);
    for (int i = 0; i < n; ++i) scanf("%20s", present[i]);
    for (int i = 0; i < m; ++i) {
        int found = 0;
        for (int j = 0; j < n; ++j) if (strcmp(all[i], present[j]) == 0) found = 1;
        puts(found ? "YES" : "NO");
    }
    return 0;
}
