#include <stdio.h>
#include <string.h>

int main(void) {
    int n, answer = 0; char a[100][21]; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%20s", a[i]);
    for (int i = 0; i < n; ++i) {
        int earlier = 0, count = 0;
        for (int j = 0; j < i; ++j) if (strcmp(a[i], a[j]) == 0) earlier = 1;
        if (earlier) continue;
        for (int j = i; j < n; ++j) if (strcmp(a[i], a[j]) == 0) ++count;
        if (count >= 2) ++answer;
    }
    printf("%d\n", answer); return 0;
}
