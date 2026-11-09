#include <stdio.h>

int main(void) {
    int n, pass = 0, excellent = 0; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int score; scanf("%d", &score);
        if (score >= 60) ++pass;
        if (score >= 80) ++excellent;
    }
    puts(100LL * pass >= 95LL * n && 100LL * excellent >= 60LL * n ? "Yes" : "No");
    return 0;
}
