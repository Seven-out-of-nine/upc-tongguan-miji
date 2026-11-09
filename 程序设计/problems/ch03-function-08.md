# 【函数】F7.08 偶数分解【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第8题。

## 题目

【函数】F7.08 偶数分解【★】

【题目描述】

编写函数实现对整数进行分解。具体要求是：输入若干个大于2的正整数，如果该数是偶数，则将其分解为两个素数（只需找出第一对素数）并输出；如果输入的奇数，则输出“××× is odd number!” ；输入为0时程序结束。只有1和它本身这两个因数的自然数叫做素数，0和1既不是素数也不是和数。

【输入】

大于2的整数序列。

【输出】

如果是偶数，则输出偶数被分解为两个素数和的表达式，否则，输出是奇数。

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
    int m, c, i;
    for(m = 1;; m++)
    {
        scanf("%d", &c);
        if(c == 0)  break;
        if(c % 2 == 0)
        {
            for(i = 2; i <= c - 2; i++)
            {
                if((fun(i) == 1) && (fun(c - i) == 1))
                {
                    printf("%d=%d+%d\n", c, i, c - i);
                    break;
                }
            }
        }
        if(c % 2 != 0)
        {
            printf("%d is odd number!\n", c);
        }
    }
    return 0;
}
```

例如:

**输入：**

```text
3 4 0
```

**输出：**

```text
3 is odd number!
4=2+2
```

### 题目与实现说明

- 完整程序保留原main；输入须依题意以0结束。

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int fun(int num)
{
    if (num < 2) return 0;
    for (int d = 2; d <= num / d; ++d)
        if (num % d == 0) return 0;
    return 1;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int fun(int num)
{
    if (num < 2) return 0;
    for (int d = 2; d <= num / d; ++d)
        if (num % d == 0) return 0;
    return 1;
}

int main()
{
    int m, c, i;
    for(m = 1;; m++)
    {
        scanf("%d", &c);
        if(c == 0)  break;
        if(c % 2 == 0)
        {
            for(i = 2; i <= c - 2; i++)
            {
                if((fun(i) == 1) && (fun(c - i) == 1))
                {
                    printf("%d=%d+%d\n", c, i, c - i);
                    break;
                }
            }
        }
        if(c % 2 != 0)
        {
            printf("%d is odd number!\n", c);
        }
    }
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-08.c)

## 讲解

1. 原main反复读取c，遇到0结束；奇数直接输出提示。
2. 偶数从i=2开始试，分别用fun检查i和c-i是不是素数。
3. fun排除小于2的数，尝试所有不超过平方根的因数，返回1表示素数。
4. 例如10从2开始，2+8不合格，3+7合格，立即输出10=3+7并停止寻找。

## 知识点总结

- 逻辑与&&：两边都为真，才说明两个加数都是素数。
- break：main找到第一对后退出当前寻找循环，符合只输出第一对的要求。
- num%d：用于判断整除；返回值0和1供main判断。

## 易错点

- 判素数函数必须排除0和1。
- 0只作为结束标记，不能当成偶数再尝试分解。

## 相似题目

- [【函数】F7.03 素数的判断【★】](ch03-function-03.md)：共同练习：素数、试除法、函数。
- [8.34 统计素数【★★】](ch05-array-34.md)：共同练习：素数。

## 再练一个用例

同时检查第一对素数和奇数分支。。

**输入：**

```text
10 7 0
```

**输出：**

```text
10=3+7
7 is odd number!
```

---

[上一题：【函数】F7.07 长整型截短【★★】](ch03-function-07.md) · [下一题：【函数】F7.09 公式求解【★】](ch03-function-09.md)
