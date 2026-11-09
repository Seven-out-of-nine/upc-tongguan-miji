#include <stdio.h>

int main(void) {
    int fibonacci[1000] = {0};
    int a = 1, b = 1;
    while (a <= 999) {
        fibonacci[a] = 1;
        int next = a + b; a = b; b = next;
    }
    int weight, count = 0;
    while (scanf("%d", &weight) == 1)
        if (weight >= 1 && weight <= 999 && fibonacci[weight]) ++count;
    printf("%d\n", count); return 0;
}
