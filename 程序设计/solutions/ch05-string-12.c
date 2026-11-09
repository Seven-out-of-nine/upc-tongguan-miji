#include <stdio.h>
#include <string.h>

int main(void) {
    char word[1001]; int count = 0;
    while (scanf("%1000s", word) == 1) {
        if (strcmp(word, "stop") == 0) break;
        ++count;
    }
    printf("%d\n", count); return 0;
}
