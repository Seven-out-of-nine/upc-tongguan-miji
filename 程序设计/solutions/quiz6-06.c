#include <stdio.h>
#include <string.h>

int main(void) {
    int n, maximum = 0;
    while (scanf("%d", &n) == 1 && n != -1) {
        int total = 18;
        for (int i = 0; i < n; ++i) {
            char color[16]; scanf("%15s", color);
            int weight = 0;
            if (strcmp(color,"red") == 0) weight = 25;
            else if (strcmp(color,"blue") == 0) weight = 20;
            else if (strcmp(color,"yellow") == 0) weight = 15;
            else if (strcmp(color,"green") == 0) weight = 10;
            else if (strcmp(color,"brown") == 0) weight = 5;
            total += 2 * weight;
        }
        printf("%d\n", total);
        if (total > maximum) maximum = total;
    }
    printf("max=%d\n", maximum); return 0;
}
