#include <stdio.h>

long long NextTerm(int index, int n, long long previous, long long current)
{
    if (index == n) return current;
    long long next;
    if ((index + 1) % 2 == 0) next = current - previous;
    else next = current + previous;
    return NextTerm(index + 1, n, current, next);
}

int Fun(int n)
{
    if (n <= 2) return 1;
    return (int)NextTerm(2, n, 1, 1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",Fun(n));
    return 0;
}
