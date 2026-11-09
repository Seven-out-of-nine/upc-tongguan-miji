# \[5.98\]字符类型判断【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第32题。

## 题目

\[5.98\]字符类型判断【★】

【题目描述】

我们将字符分为五类：大写字母、小写字母、数字、控制字符、其他字符。

【输入】

一个字符。

【输出】

字符所属的类型：大写字母为capital letters，小写字母为small letters，数字为figures，其他字符为others。

例如:

**输入：**

```text
A
```

**输出：**

```text
capital letters
```

### 题目与实现说明

- 题目描述说分“五类”，但输出段只给出大写、小写、数字、其他四种标签；保存页的源代码额外把空格输出space，但没有该情况的已展示反馈。本解按明确的输出段，把字母和数字之外的字符输出others。

## 解答

```c
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
```

[下载完整源码](../solutions/ch03-branch-32.c)

## 讲解

1. 按输出段明确给出的规则，将字符归为大写字母、小写字母、数字或其他。
2. 使用三个范围判断，三者都不满足就输出others。
3. 例如A属于A到Z，输出capital letters；问号?不在三种范围内，输出others。

## 知识点总结

- 字符范围：ASCII中字母和数字的编码各自连续，可以用>=、<=检查。
- 逻辑与&&：同一个字符必须同时满足范围的下界和上界。
- getchar：读取字符时保留空格等空白，不擅自跳过。

## 易错点

- 本题单词与“判断字符类型”题不同：这里数字为figures、大写为capital letters，不能照抄另题的figure、capital。
- 原题没有明确控制字符的专门输出标签，不能凭空造一个标签。

## 相似题目

- [\[5.21\]判断字符类型★★](ch03-branch-21.md)：共同练习：字符、ASCII、条件分支。
- [\[4.03\]字符的ASCII值★](ch02-16.md)：共同练习：字符、ASCII。
- [10.14 合法标识符【★★】](ch05-string-14.md)：可对照练习：字符串、条件判断，比较输入、处理步骤和输出的变化。

## 再练一个用例

非字母数字的符号。

**输入：**

```text
?
```

**输出：**

```text
others
```

---

[上一题：\[5.31\]出租车计费★★](ch03-branch-31.md) · [下一题：\[5.99\]三角形形状判断【★★】](ch03-branch-33.md)
