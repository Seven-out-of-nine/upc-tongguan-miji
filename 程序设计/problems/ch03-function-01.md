# 【函数】F7.01求最大值【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第1题。

## 题目

【函数】F7.01求最大值【★】

【题目描述】

请编写一个求两整数的最大值函数GetMax。要求在主函数中调用该函数，该函数的主要功能是判断从键盘任意输入两个整数的大小，计算并输出最大值。

【输入】

两个整数。

【输出】

两个整数中的最大值。

预设代码

前置代码

```text
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
```

后置代码

```text
int main()
{
    int num1,num2,max;
    scanf("%d%d",&num1,&num2);
    max = GetMax(num1,num2);
    printf("MAX=%d\n",max);
    return 0;
}
```

例如:

**输入：**

```text
10 20
```

**输出：**

```text
MAX=20
```

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int GetMax(int a, int b)
{
    if (a > b) return a;
    return b;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int GetMax(int a, int b)
{
    if (a > b) return a;
    return b;
}

int main()
{
    int num1,num2,max;
    scanf("%d%d",&num1,&num2);
    max = GetMax(num1,num2);
    printf("MAX=%d\n",max);
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-01.c)

## 讲解

1. main读入两个整数，调用GetMax，把两个输入值分别交给形参a、b。
2. 如果a大于b，立即返回a；否则返回b，相等时返回任意一个都正确。
3. 例如10和20比较，10>20不成立，函数返回20，main输出MAX=20。

## 知识点总结

- 函数定义int GetMax(int a,int b)：前面的int规定返回整数，括号中的两个int是接收输入值的形参。
- if(a>b)：比较结果成立时执行紧随的return语句。
- return：把结果交回调用位置；函数返回数值，main负责按MAX=%d的格式输出。

## 易错点

- 函数名GetMax区分大小写，写成getmax无法与原main的调用对应。

## 相似题目

- [\[5.25\] 最大值★](ch03-branch-25.md)：可对照练习：最值、条件分支，比较输入、处理步骤和输出的变化。
- [8.11 矩阵最大值【★】](ch05-array-11.md)：可对照练习：二维数组、最大值，比较输入、处理步骤和输出的变化。

## 再练一个用例

两个数都为负数，不能把最大值初始设成0。。

**输入：**

```text
-8 -3
```

**输出：**

```text
MAX=-3
```

---

[下一题：【函数】F7.02 数的合并【★】](ch03-function-02.md)
