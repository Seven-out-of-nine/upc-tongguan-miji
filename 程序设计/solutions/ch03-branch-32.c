#include <stdio.h>

int main(void)
{
    int ch = getchar();
    if (ch >= 'A' && ch <= 'Z') puts("capital letters");
    else if (ch >= 'a' && ch <= 'z') puts("small letters");
    else if (ch >= '0' && ch <= '9') puts("figures");
    else puts("others");
    return 0;
}
