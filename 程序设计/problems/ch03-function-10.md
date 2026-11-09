# 【函数】F7.10 杀鸡用牛刀【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第10题。

## 题目

【函数】F7.10 杀鸡用牛刀【★★★】

【题目描述】

哈哈！我们终于学了递归了，现在大家一定感到非常有意思吧，那个典型的“汉诺塔”问题，一个非常短的程序居然可以完成如此复杂的工作，真是神奇啊！来吧，让我们也动手编写一个递归程序，当然，我们要编写的不可能太复杂。功能：从键盘录入两个数n和m来表示一个区间， n 为区间的起始点，m为区间的终止点 ，求整数 n 到 m 区间的累加和，其中n&lt;=m。

【输入】

两个整数n和m。

【输出】

n 到 m 区间的累加和。

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
    int m,n,s;
    scanf("%d%d",&n,&m);
    s=GetSum(n,m);
    printf("%d\n",s);
    return 0;
}
```

例如:

**输入：**

```text
1 100
```

**输出：**

```text
5050
```

### 题目与实现说明

- 原参考答案使用等差数列公式，没有满足题目明确要求的递归，本解已改为递归。

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
long long SumInterval(int n, int m)
{
    if (n == m) return n;
    int mid = n + (int)(((long long)m - n) / 2);
    return SumInterval(n, mid) + SumInterval(mid + 1, m);
}

int GetSum(int n, int m)
{
    return (int)SumInterval(n, m);
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

long long SumInterval(int n, int m)
{
    if (n == m) return n;
    int mid = n + (int)(((long long)m - n) / 2);
    return SumInterval(n, mid) + SumInterval(mid + 1, m);
}

int GetSum(int n, int m)
{
    return (int)SumInterval(n, m);
}

int main()
{
    int m,n,s;
    scanf("%d%d",&n,&m);
    s=GetSum(n,m);
    printf("%d\n",s);
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-10.c)

## 讲解

1. 按题意使用递归，把区间内所有整数累加，包含两个端点。
2. 如果n==m，区间只剩一个数，直接返回它，作为递归终点。
3. 否则用mid把区间分成[n,mid]、[mid+1,m]，分别求和再相加，分段使递归层数较少。
4. 例如2到5分成2到3和4到5，结果(2+3)+(4+5)=14。

## 知识点总结

- **递归调用与终止条件**：递归是在函数内再次调用自身来处理更小的同类问题。每次调用都有自己的参数；本题区间只剩一个数时直接返回，其他调用等待较短区间的结果再返回。必须有能到达的终止条件，且参数持续朝该条件推进。
- **分治：拆分、求解、合并**：把[n,m]在mid处分为[n,mid]和[mid+1,m]，分别求和后相加。两个子区间不重叠且完整覆盖原区间，所以合并结果就是原问题答案；每次近似对半拆分还能降低递归调用的最大层数。

## 易错点

- 右半段必须从mid+1开始，否则中点会重复相加，或区间无法缩小。
- 原main及GetSum返回值均为int，最终区间和须在int范围内；子区间和由long long保存。

## 相似题目

- [【函数】F7.11 求最大公约数【★★★】](ch03-function-11.md)：共同练习：递归、函数。
- [【函数】F7.12 求数列的第N项【★】](ch03-function-12.md)：共同练习：递归、函数。

## 再练一个用例

两个端点都应计入。。

**输入：**

```text
2 5
```

**输出：**

```text
14
```

---

[上一题：【函数】F7.09 公式求解【★】](ch03-function-09.md) · [下一题：【函数】F7.11 求最大公约数【★★★】](ch03-function-11.md)
