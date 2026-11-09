# 【函数】F7.12 求数列的第N项【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第12题。

## 题目

【函数】F7.12 求数列的第N项【★】

【题目描述】

已知整数数列第一项和第二项是1，该数列从第三项开始，如果该项是奇数项，则它是前两项之和，如果该项是偶数项，则它是前两项之差，即：

f( n ) = 1 当 n = 1 或 2 时，

f( n ) = f( n-1 ) - f( n-2 ) 当n是偶数时，

f( n ) = f( n-1 ) + f( n-2 ) 当n是奇数时，

编写一个递归函数，求数列的第n项。

【输入】

一个整数n。

【输出】

输出数列的第n项。

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
    int n;
    scanf("%d",&n);
    printf("%d\n",Fun(n));
    return 0;
}
```

例如:

**输入：**

```text
1
```

**输出：**

```text
1
```

### 题目与实现说明

- 原参考答案用循环，没有满足递归要求，本解使用保存相邻两项的线性递归。
- 原题未给n上界，原main固定按int输出。中间状态使用long long，例如第91项超过int，但第92项1836311903又在int内，需先用宽整数计算再返回。

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
long long NextTerm(int index, int n, long long previous, long long current)
{
    if (index == n) return current;
    long long next;
    if ((index + 1) % 2 == 0) next = current - previous;
    else next = current + previous;
    return NextTerm(index + 1, n, current, next);
}

int Fun(int n)
{
    if (n <= 2) return 1;
    return (int)NextTerm(2, n, 1, 1);
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

long long NextTerm(int index, int n, long long previous, long long current)
{
    if (index == n) return current;
    long long next;
    if ((index + 1) % 2 == 0) next = current - previous;
    else next = current + previous;
    return NextTerm(index + 1, n, current, next);
}

int Fun(int n)
{
    if (n <= 2) return 1;
    return (int)NextTerm(2, n, 1, 1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",Fun(n));
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-12.c)

## 讲解

1. 前两项都是1；求后面的项必须同时记住前一项previous和当前项current。
2. 辅助递归从第2项开始，计算index+1这一项：下一项序号为偶数就作差，为奇数就相加。
3. 把current与next作为新的一对相邻项，递归前进一项；index到达n时返回current。
4. 例如前六项为1、1、2、1、3、2，所以n=6返回2；这种递归每一项只计算一次。

## 知识点总结

- 辅助函数：NextTerm携带序号和相邻两项，Fun仍保留原main需要的单参数接口。
- long long状态：保存前项、当前项和新项；最终值可在int内，但中间项可能更大，不能过早转换。
- (index+1)%2：判定的是即将计算的项序号，不是当前项的数值。
- 递归参数更新：previous变成current，current变成next，等价于把相邻窗口向前移动。

## 易错点

- 偶数项是前一项减前两项，方向不能颠倒。
- 原main用int输出，n须为正且最终结果在int可表示范围内；最后才将long long结果转为int。

## 相似题目

- [【函数】F7.10 杀鸡用牛刀【★★★】](ch03-function-10.md)：共同练习：递归、函数。
- [【函数】F7.11 求最大公约数【★★★】](ch03-function-11.md)：共同练习：递归、函数。

## 再练一个用例

同时覆盖奇数项相加与偶数项相减。。

**输入：**

```text
6
```

**输出：**

```text
2
```

---

[上一题：【函数】F7.11 求最大公约数【★★★】](ch03-function-11.md) · [下一题：【函数】F7.13富翁与骗子【★★】](ch03-function-13.md)
