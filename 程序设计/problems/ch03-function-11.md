# 【函数】F7.11 求最大公约数【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第11题。

## 题目

【函数】F7.11 求最大公约数【★★★】

【题目描述】

请使用递归算法计算正整数n和m的最大公约数Gcd(n,m)。‌递归实现求最大公约数的思想主要基于辗转相除法（Euclidean Algorithm）。‌这种方法通过不断地将两个数中较大的数除以较小的数，得到余数，然后将较小的数和余数再进行相除，重复这个过程，直到余数为0时，较小的数就是最大公约数。

【输入】

两个整数n和m。

【输出】

两个整数的最大公约数。

预设代码

前置代码

```text
#include "stdio.h"
#include <bits/stdc++.h>
using namespace std;
```

后置代码

```text
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",Gcd(n,m));
    return 0;
}
```

例如:

**输入：**

```text
24 48
```

**输出：**

```text
24
```

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int Gcd(int n, int m)
{
    if (m == 0) return n;
    return Gcd(m, n % m);
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int Gcd(int n, int m)
{
    if (m == 0) return n;
    return Gcd(m, n % m);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",Gcd(n,m));
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-11.c)

## 讲解

1. 两个正整数的公约数，与较小数和相除余数的公约数相同。
2. 因此每次把(n,m)换成(m,n%m)，继续递归求解。
3. 当m为0时，前一轮的除数n就是最大公约数，直接返回。
4. 例如Gcd(18,12)调用Gcd(12,6)，再调用Gcd(6,0)，最终得到6。

## 知识点总结

- n%m：求整数相除的余数，是辗转相除法的关键。
- return Gcd(...)：把下一层递归计算出的结果返回给上一层。
- 先检查m==0：检查在取余之前执行，保证不会对0取余。

## 易错点

- 递归参数的顺序是m,n%m，不能仍传原来的n,m。
- 本题规定正整数，负数的最大公约数符号需另行规范。

## 相似题目

- [【函数】F7.10 杀鸡用牛刀【★★★】](ch03-function-10.md)：共同练习：递归、函数。
- [【函数】F7.12 求数列的第N项【★】](ch03-function-12.md)：共同练习：递归、函数。

## 再练一个用例

两数不互为整倍数，需要多轮辗转相除。。

**输入：**

```text
18 12
```

**输出：**

```text
6
```

---

[上一题：【函数】F7.10 杀鸡用牛刀【★★★】](ch03-function-10.md) · [下一题：【函数】F7.12 求数列的第N项【★】](ch03-function-12.md)
