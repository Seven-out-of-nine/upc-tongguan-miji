# 10.23 指定位置插入字符串【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第23题。

## 题目

【题目描述】

输入两个字符串 s1 、 s2 和 s1 中任意字符 k 。在 s1 中第一次出现指定字符 k的位置处插入字符串 s2 并输出。

【输入】

有三行，两个字符串 s1 、 s2 和 s1 中任意字符 k，各占1行，字符串中无空格，长度均不超过100。

【输出】

插入后的字符串s1。

提示：用string类及操作函数会极大降低难度。

例如:

**输入：**

```text
beijing
123
j
```

**输出：**

```text
bei123jing
```

## 解答

```c
#include <stdio.h>

int main(void) {
    char a[101], b[101], c; scanf("%100s%100s %c", a, b, &c);
    int inserted = 0;
    for (int i = 0; a[i]; ++i) {
        if (!inserted && a[i] == c) { printf("%s", b); inserted = 1; }
        putchar(a[i]);
    }
    putchar('\n'); return 0;
}
```

[下载完整源码](../solutions/ch05-string-23.c)

## 讲解

1. 从左到右输出s1，另设标记说明是否已插入。
2. 第一次遇到字符k时，先输出整个s2，再继续输出原字符。
3. 例如banana、X、a会在第一个a前插入，得到bXanana。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 插入发生在k之前；原来的k仍需输出。

## 相似题目

- [10.19 字符串删除【★】](ch05-string-19.md)：共同练习：字符串。
- [10.30 字符第一次出现的位置【★】](ch05-string-30.md)：共同练习：字符串、查找。

## 再练一个用例

检查只在第一次出现处插入。。

**输入：**

```text
banana
X
a
```

**输出：**

```text
bXanana
```

---

[上一题：10.22 字符接龙【★】](ch05-string-22.md) · [下一题：10.24 字符串比较大小【★】](ch05-string-24.md)
