#include <stdio.h>

int main(void)
{
    int ch = getchar();
    if (ch >= '0' && ch <= '9') puts("figure");
    else if (ch >= 'A' && ch <= 'Z') puts("capital");
    else if (ch >= 'a' && ch <= 'z') puts("lowercase");
    else if (ch == ' ') puts("space");
    else puts("other");
    return 0;
}
