#include <stdio.h>

int main(void) {
    char s[27]; scanf("%26s", s);
    for (int i = 0; s[i]; ++i) {
        char base = s[i] >= 'a' && s[i] <= 'z' ? 'a' : 'A';
        s[i] = base + (s[i] - base + 4) % 26;
    }
    puts(s); return 0;
}
