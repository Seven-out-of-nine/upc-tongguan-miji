# \[5.11\]判断三角形的形状★★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第11题。

## 题目

**描述**

输入三角型的三条边，判断三角形的形状。注意边长应当&gt;0。

输入：

三角型的3条边的长度（int型）。

输出：

根据三角形形状，输出对应的英文。

等边三角形：equilateral triangle
等腰三角形：isoceles triangle
不构成三角形：non-triangle
一般三角形：triangle

例如:

**输入：**

```text
2 2 2
```

**输出：**

```text
equilateral triangle
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        puts("non-triangle");
    } else if (a == b && b == c) {
        puts("equilateral triangle");
    } else if (a == b || a == c || b == c) {
        puts("isoceles triangle");
    } else {
        puts("triangle");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-11.c)

## 讲解

1. 先排除非正边长，以及任意两边之和不大于第三边的情况。
2. 能组成三角形后，先判断三边相等，再判断至少两边相等，剩下的是一般三角形。
3. 例如2、2、2先满足等边条件；2、2、3只满足等腰条件；1、2、3因为1+2不大于3而不能组成三角形。

## 知识点总结

- 逻辑或||：任何一项非法就属于non-triangle。
- 判断顺序：等边三角形也满足“两边相等”，因此等边必须放在等腰之前。
- long long：用较宽整数保存边长，使两边相加比普通int更不易溢出。

## 易错点

- 两边和恰好等于第三边也不能组成三角形，要写<=而不是<。
- isoceles是原题要求的拼写，提交时应按其输出。

## 相似题目

- [\[5.99\]三角形形状判断【★★】](ch03-branch-33.md)：共同练习：条件分支、几何判断、逻辑运算。
- [\[3.10\]求三角形面积★★](ch02-13.md)：可对照练习：公式计算、数学函数，比较输入、处理步骤和输出的变化。
- [\[5.03\]寻找不一样的信号★★](ch03-branch-03.md)：共同练习：条件分支。

## 再练一个用例

退化三角形。

**输入：**

```text
1 2 3
```

**输出：**

```text
non-triangle
```

---

[上一题：\[5.10\] 四位数拆分★](ch03-branch-10.md) · [下一题：\[5.12\]判断某年某月的天数★★](ch03-branch-12.md)
