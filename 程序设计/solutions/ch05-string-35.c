#include <stdio.h>
#include <string.h>

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char s[100]; scanf("%99s", s);
        puts(strstr(s, "GLB") != NULL ? "YES" : "NO");
    }
    return 0;
}
