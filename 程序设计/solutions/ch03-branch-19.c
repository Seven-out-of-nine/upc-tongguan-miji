#include <stdio.h>

int main(void)
{
    long long a, b;
    char op;
    scanf("%lld %c %lld", &a, &op, &b);
    switch (op) {
        case '+': printf("%lld+%lld=%lld\n", a, b, a + b); break;
        case '-': printf("%lld-%lld=%lld\n", a, b, a - b); break;
        case '*': printf("%lld*%lld=%lld\n", a, b, a * b); break;
        case '/': printf("%lld/%lld=%.3f\n", a, b, (double)a / b); break;
    }
    return 0;
}
