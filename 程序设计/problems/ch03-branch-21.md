# \[5.21\]判断字符类型★★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第21题。

## 题目

**描述**

从键盘任意输入一个字符，编程判断该字符是数字、大写字母、小写字母、空格还是其他字符。

若是数字输出figure，大写字母输出capital，小写字母输出lowercase，空格输出space，其他字符输出other

（'0'-'9'的ASCLL码为48-57；'A'-'Z'的ASCLL码为65-90；'a'-'z'的ASCLL码为97-122；空格的ASCLL为32）

**输入**

一个字符c

**输出**

该字符的类型

例如:

**输入：**

```text
a
```

**输出：**

```text
lowercase
```

## 解答

```c
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
```

[下载完整源码](../solutions/ch03-branch-21.c)

## 讲解

1. 用getchar读取第一个字符，包括空格在内。
2. 依次检查数字、大写字母、小写字母的编码范围，再单独检查空格，剩下的都是other。
3. 例如输入a，属于'a'到'z'的范围，输出lowercase；输入一个空格则输出space。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 不能使用scanf(" %c",...)读取本题字符，格式里的空格会跳过要判断的空格。
- 不要把figure、capital等输出词换成自己理解的中文。

## 相似题目

- [\[4.03\]字符的ASCII值★](ch02-16.md)：共同练习：字符、ASCII。
- [\[5.98\]字符类型判断【★】](ch03-branch-32.md)：共同练习：字符、ASCII、条件分支。
- [10.14 合法标识符【★★】](ch05-string-14.md)：可对照练习：字符串、条件判断，比较输入、处理步骤和输出的变化。

## 再练一个用例

空格不能被输入函数跳过。

**输入：**

```text

```

**输出：**

```text
space
```

---

[上一题：\[5.20\]判断成绩区间★★](ch03-branch-20.md) · [下一题：\[5.22\]体型判断★★★](ch03-branch-22.md)
