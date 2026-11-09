# 10.04 数字提取【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第4题。

## 题目

10.04 数字提取【★】

【题目描述】

提取一个字符串中的所有数字字符（‘0’...‘9’）将其转换为一个整数输出。

【输入】

一个以回车符为结束标志的字符串（少于80个字符）。

【输出】

把字符串中的所有数字字符（‘0’...‘9’）转换为一个整数并输出。

例如:

**输入：**

```text
free82jeep5
```

**输出：**

```text
825
```

### 题目与实现说明

- 用字符保存提取的整数，避免题干允许近80位数字时发生整型溢出；没有数字时按0输出。

## 解答

```c
#include <stdio.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    char s[83], digits[83]; int n = 0;
    read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i)
        if (s[i] >= '0' && s[i] <= '9') digits[n++] = s[i];
    digits[n] = '\0';
    int first = 0;
    while (first < n && digits[first] == '0') ++first;
    if (first == n) puts("0"); else puts(digits + first);
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-04.c)

## 讲解

1. 扫描原串，只把0到9之间的字符依次复制到digits。
2. 整数不显示前导零，因此从digits开头跳过所有0。
3. 例如a00b12得到0012，再输出12；全为0或没有数字时输出0。

## 知识点总结

- n++：先使用当前位置，再把已收集数字数加1。
- `digits[n] = '\0'`：为新串补上结束标志。
- digits+first：从首个非零数字所在位置开始输出。

## 易错点

- 输入可能有很多位数字，不能用int反复乘10，否则会溢出。
- 不能对数字排序，必须保留出现顺序。

## 相似题目

- [10.05 整数分离【★★】](ch05-string-05.md)：共同练习：字符串、数字提取。
- [10.37 营业额【★★★】](ch05-string-37.md)：共同练习：字符串、大整数。

## 再练一个用例

检查跨段拼接和前导零。。

**输入：**

```text
a000b007c0
```

**输出：**

```text
70
```

---

[上一题：10.03 字符变换【★】](ch05-string-03.md) · [下一题：10.05 整数分离【★★】](ch05-string-05.md)
