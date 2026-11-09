#include <stdio.h>

int main(void) {
    const char *names[] = {"Circle dance","Doc","Bashful","Sleepy","Sneezy","Happy","Dopey","Grumpy"};
    int n;
    while (scanf("%d", &n) == 1) {
        int d = n % 10;
        puts(d >= 1 && d <= 7 ? names[d] : names[0]);
    }
    return 0;
}
