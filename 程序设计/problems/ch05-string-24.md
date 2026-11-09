# 10.24 字符串比较大小【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第24题。

## 题目

【题目描述】

输入两个均不含有空格的字符串s和t，对s和t比较大小。

【输入】

两个字符串s和t，每个字符串长度不超过100。

【输出】

如果s大于t，输出“s&gt;t”；如果s等于t，输出“s=t”；如果s小于t，输出“s&lt;t”。

例如:

**输入：**

```text
CBA
CAB
```

**输出：**

```text
s>t
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101], t[101]; scanf("%100s%100s", s, t);
    int result = strcmp(s, t);
    if (result > 0) puts("s>t"); else if (result < 0) puts("s<t"); else puts("s=t");
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-24.c)

## 讲解

1. 用strcmp从左到右比较两个串的字符编码。
2. 遇到第一处不同字符就决定大小；前缀相同则较短串更小。
3. 例如ab与abc前两个字符相同，但ab已结束，因此输出s<t。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 字符串不能用==比较内容，那样比较的是地址。
- strcmp返回正数不一定恰好是1。

## 相似题目

- [10.25 相同的字符串【★★★】](ch05-string-25.md)：共同练习：字符串。
- [10.29 城市名排序【★★】](ch05-string-29.md)：共同练习：字符串、字典序。

## 再练一个用例

检查一个串是另一个串的前缀。。

**输入：**

```text
ab abc
```

**输出：**

```text
s<t
```

---

[上一题：10.23 指定位置插入字符串【★★】](ch05-string-23.md) · [下一题：10.25 相同的字符串【★★★】](ch05-string-25.md)
