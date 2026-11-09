# 8.02 A+B Format【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第2题。

## 题目

**【题目描述】**

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

**【输入】**

Only one line. Contains two integers a and b(-1000000≤a, b≤1000000). The numbers are separated by a space.

**【输出】**

Only one line. Output the sum of a and b in one line. The sum must be written in the standard format.

例如:

**输入：**

```text
-1000000 9↵
```

**输出：**

```text
-999,991
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a, b, sum;
    char digits[16];
    scanf("%d%d", &a, &b);
    sum = a + b;
    if (sum < 0) { putchar('-'); sum = -sum; }
    sprintf(digits, "%d", sum);
    int length = (int)strlen(digits);
    for (int i = 0; i < length; ++i) {
        putchar(digits[i]);
        if (i + 1 < length && (length - i - 1) % 3 == 0) putchar(',');
    }
    putchar('\n');
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-02.c)

## 讲解

1. 先求a+b，若和为负，单独输出负号，再处理绝对值的数字。
2. 把非负的和写入字符数组，从左向右逐位输出。
3. 某一位后面剩余的数字数若为3的倍数且不为0，就在这一位后加逗号。
4. 例如-999991处理为999991，输出前三位后还剩3位，最终为-999,991。

## 知识点总结

- sprintf(digits,"%d",sum)：把整数转换为十进制字符串；本题最多7位数字，16字节足够。
- strlen来自string.h：返回终止符\0之前的字符数。
- &&表示两个条件必须都满足，用来避免在最后一位后输出逗号。

## 易错点

- 负号不能算进数字分组长度。
- 和为0时应输出0，不能输出空行；转换成字符串可直接处理。

## 相似题目

- [8.26 各位数字组最大数【★★】](ch05-array-26.md)：可对照练习：数位拆分、频数统计，比较输入、处理步骤和输出的变化。
- [【函数】F7.02 数的合并【★】](ch03-function-02.md)：共同练习：整数运算。

## 再练一个用例

正负抵消时仍需输出一个0。。

**输入：**

```text
-500 500
```

**输出：**

```text
0
```

---

[上一题：8.01 小明摘苹果【★】](ch05-array-01.md) · [下一题：8.03 矩阵存储【★】](ch05-array-03.md)
