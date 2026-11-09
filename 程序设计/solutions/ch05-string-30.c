#include <stdio.h>

int main(void) {
    char s[101], ch; scanf("%100s %c", s, &ch);
    int position = 0;
    for (int i = 0; s[i]; ++i) if (s[i] == ch) { position = i + 1; break; }
    printf("%d\n", position); return 0;
}
