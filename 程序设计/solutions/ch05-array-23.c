#include <stdio.h>

int Contains(const int values[], int n, int target)
{
    for (int i = 0; i < n; ++i)
        if (values[i] == target) return 1;
    return 0;
}

int main(void)
{
    int n, m, first[20], second[20], answer[40], length = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &first[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &second[i]);
    for (int i = 0; i < n; ++i)
        if (!Contains(second, m, first[i]) && !Contains(answer, length, first[i])) answer[length++] = first[i];
    for (int i = 0; i < m; ++i)
        if (!Contains(first, n, second[i]) && !Contains(answer, length, second[i])) answer[length++] = second[i];
    for (int i = 0; i < length; ++i) {
        if (i) putchar(' ');
        printf("%d", answer[i]);
    }
    putchar('\n');
    return 0;
}
