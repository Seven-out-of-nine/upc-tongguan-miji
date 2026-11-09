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

- **C字符串与结束符**：char digits[16]可保存连续字符；C字符串用字符常量'\0'标记内容结束，这个字节不属于显示的数字，所以容量至少比内容长度多1。它和数字字符'0'不同，后者仍是字符串的一部分。
- **sprintf把整数写成字符串**：sprintf(digits,"%d",sum)按与printf相同的数字格式把结果写进digits数组，并在末尾补'\0'；本题和值最多7位，16格足够。它不会自动知道目标容量，必须先确保数组能放下所有字符及结束符。
- **strlen取得字符串内容长度**：strlen(digits)返回首个'\0'之前的字符数，不包含结束符，需要string.h。它给出的是当前内容长度，和数组预留的16格容量不同；本题借此判断每一位后面还剩多少数字。
- **putchar输出单个字符**：putchar(digits[i])只输出当前这一格字符，也可用putchar(',')打印分隔逗号。它每次处理一个字符，适合逐位组合输出；输出整行结束时再单独调用putchar('\n')。

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
