# TJ8.07 数制转换【★★★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第46题。

## 题目

【题目描述】

我们通常使用的都是十进制的数字，但其实在生活中也经常会使用其它进制。给你两个不同的数字，它们不属于同一进制，要求你计算出当它们分别处于何种进制之中时，两个数字相等。譬如 12 和 5 ，在十进制下它们是不等的，但若 12 使用 3 进制而 5 使用六进制或十进制时，它们的值就是相等的。因此只要选择合适的进制， 12 和 5 就可以是相等的。

【输入】

两个数字 M 和 N( 其十进制的值不超过 1000000000)。它们的进制在2--36之间。对于十以下的数字，用0--9表示，而十以上的数字，则使用大写的A--Z表示。

【输出】

分别在 2--36 哪种进制下 M 和 N 相等。若相等则输出相应的进制，若不等则输出错误信息。信息的格式见测试用例。

例如:

**样例 1**

**输入：**

```text
12 5
```

**输出：**

```text
12 (base 3) = 5 (base 6)
```

**样例 2**

**输入：**

```text
123 456
```

**输出：**

```text
123 is not equal to 456 in any base 2..36
```

**样例 3**

**输入：**

```text
10 A
```

**输出：**

```text
10 (base 10) = A (base 11)
```

### 题目与实现说明

- 多组进制可能都满足时，题干未明说选择次序；本解按原参考答案，先最小M进制、再最小N进制。
- 转换上限按题干“其十进制的值不超过1000000000”处理。

## 解答

```c
#include <stdio.h>

int DigitValue(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

long long Convert(const char text[], int base)
{
    long long value = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        int digit = DigitValue(text[i]);
        if (digit >= base || value > (1000000000LL - digit) / base) return -1;
        value = value * base + digit;
    }
    return value;
}

int main(void)
{
    char m[65], n[65];
    scanf("%64s%64s", m, n);
    for (int base_m = 2; base_m <= 36; ++base_m) {
        long long a = Convert(m, base_m);
        if (a < 0) continue;
        for (int base_n = 2; base_n <= 36; ++base_n) {
            long long b = Convert(n, base_n);
            if (b >= 0 && a == b) {
                printf("%s (base %d) = %s (base %d)\n", m, base_m, n, base_n);
                return 0;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n", m, n);
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-46.c)

## 讲解

1. 把字符0到9解释为0到9，把A到Z解释为10到35；某位数字若不小于所试进制，该进制就不合法。
2. 固定一个进制时，从左到右用value=value*base+digit求十进制值，例如三进制12等于1×3+2=5。
3. 从2到36依次枚举M的进制，对每一个再枚举N的进制，找到首对相等值后输出。
4. 例如12先能在三进制表示5，字符5的最小合法进制为6，故首组答案是base 3与base 6。
5. 依据题意十进制值不超过10⁹，在乘法前检查是否超限，非法或超限返回-1，防止转换溢出。

## 知识点总结

- const char text[]：函数读取一串字符，并在\0处停止。
- 字符减法：'A'-'A'+10=10，用统一规则支持大写字母数字。
- continue：跳过M当前非法进制，开始下一次外层枚举。
- 嵌套枚举与return：由小到大尝试进制，找到第一对立即结束，确定多解时的输出顺序。
- value>(limit-digit)/base：在执行value*base+digit之前判断上界。

## 易错点

- 合法最小进制至少是2，数字0或1不能让进制变成1。
- A表示10，因此至少需要11进制；同理Z至少需要36进制。

## 相似题目

- [8.26 各位数字组最大数【★★】](ch05-array-26.md)：可对照练习：数位拆分、频数统计，比较输入、处理步骤和输出的变化。
- [【函数】F7.02 数的合并【★】](ch03-function-02.md)：可对照练习：数位拆分、函数，比较输入、处理步骤和输出的变化。

## 再练一个用例

只有0和1时最低合法进制为2，前导零不改变数值。。

**输入：**

```text
1 01
```

**输出：**

```text
1 (base 2) = 01 (base 2)
```

---

[上一题：TJ8.04 矩阵加法【★】](ch05-array-45.md) · [下一题：TJ8.08 The Himalayas【★★★】](ch05-array-47.md)
