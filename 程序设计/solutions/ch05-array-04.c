#include <stdio.h>

/* digits[j][k]保存当前行第j项的第k个十进制数字，低位在前。 */
int main(void)
{
    int n, digits[100][31] = {{0}};
    scanf("%d", &n);
    digits[0][0] = 1;
    for (int row = 0; row < n; ++row) {
        if (row > 0) {
            for (int col = row; col >= 1; --col) {
                int carry = 0;
                for (int k = 0; k < 31; ++k) {
                    int sum = digits[col][k] + digits[col - 1][k] + carry;
                    digits[col][k] = sum % 10;
                    carry = sum / 10;
                }
            }
        }
        for (int col = 0; col <= row; ++col) {
            int top = 30;
            while (top > 0 && digits[col][top] == 0) --top;
            for (int space = top + 1; space < 6; ++space) putchar(' ');
            for (int k = top; k >= 0; --k) putchar('0' + digits[col][k]);
        }
        putchar('\n');
    }
    return 0;
}
