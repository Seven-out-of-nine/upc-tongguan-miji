#include <stdio.h>
#include <string.h>

int digit(const char word[]) {
    const char *names[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i < 10; ++i) if (strcmp(word, names[i]) == 0) return i;
    return -1;
}
int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char word[16]; int a = 0, b = 0, second = 0;
        while (scanf("%15s", word) == 1 && strcmp(word, "=") != 0) {
            if (strcmp(word, "+") == 0) second = 1;
            else if (!second) a = a * 10 + digit(word);
            else b = b * 10 + digit(word);
        }
        printf("%d\n", a + b);
    }
    return 0;
}
