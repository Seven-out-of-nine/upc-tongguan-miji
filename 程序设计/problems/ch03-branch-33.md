# \[5.99\]三角形形状判断【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第33题。

## 题目

【题目描述】

输入三角型的三条边，判断三角形的形状。

【输入】

三角型的3条边的长度（均是正整数）。

【输出】

三角形的形状。其中等边三角形为equilateral triangle，等腰三角形为isoceles triangle，不构成三角形为non-triangle，一般三角形为triangle。

例如:

**输入：**

```text
2 2 2
```

**输出：**

```text
equilateral triangle.
```

### 题目与实现说明

- 文字输出列表未标句点，但原样例和保存页展示的运行结果均有句点；本解按样例输出。

## 解答

```c
#include <stdio.h>

int main(void)
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        puts("non-triangle.");
    } else if (a == b && b == c) {
        puts("equilateral triangle.");
    } else if (a == b || a == c || b == c) {
        puts("isoceles triangle.");
    } else {
        puts("triangle.");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-33.c)

## 讲解

1. 先判断任意两边之和是否大于第三边，不满足就输出non-triangle.。
2. 合法三角形中先判断三边相等的等边，再判断两边相等的等腰，否则是一般三角形。
3. 例如2、2、2输出equilateral triangle.；5、4、3三边不同且能成三角形，输出triangle.。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 本题和[5.11]内容相近，但本题样例末尾多一个英文句点，不可漏掉。
- 题目沿用isoceles拼写，输出时遵守题目字符串。

## 相似题目

- [\[5.11\]判断三角形的形状★★](ch03-branch-11.md)：共同练习：条件分支、几何判断、逻辑运算。
- [\[3.10\]求三角形面积★★](ch02-13.md)：可对照练习：公式计算、数学函数，比较输入、处理步骤和输出的变化。
- [\[5.03\]寻找不一样的信号★★](ch03-branch-03.md)：共同练习：条件分支。

## 再练一个用例

退化三角形，带句点。

**输入：**

```text
1 2 3
```

**输出：**

```text
non-triangle.
```

---

[上一题：\[5.98\]字符类型判断【★】](ch03-branch-32.md)
