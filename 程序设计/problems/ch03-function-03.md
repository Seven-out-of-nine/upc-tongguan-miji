# 【函数】F7.03 素数的判断【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第3题。

## 题目

【函数】F7.03 素数的判断【★】

【题目描述】

请编写一个判断素数的函数PrimeJudge。具体功能是对录入的一个整数num进行判断，判断其是否为素数，如果是素数，则返回1，否则返回0。

【输入】

一个整数num

【输出】

num如果是素数，则返回1，否则返回0。

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
    int num;
    scanf("%d", &num);
    if( PrimeJudge(num) )
    {
        printf("Prime\n");
    }
    else
    {
        printf("Non Prime\n");
    }
    return 0;
}
```

例如:

**输入：**

```text
13
```

**输出：**

```text
Prime
```

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int PrimeJudge(int num)
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

int PrimeJudge(int num)
{
    if (num < 2) return 0;
    for (int d = 2; d <= num / d; ++d)
        if (num % d == 0) return 0;
    return 1;
}

int main()
{
    int num;
    scanf("%d", &num);
    if( PrimeJudge(num) )
    {
        printf("Prime\n");
    }
    else
    {
        printf("Non Prime\n");
    }
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-03.c)

## 讲解

1. 小于2的整数不是素数，先直接返回0。
2. 从2开始试除；如果找到一个能整除num的d，说明还有其他因数，返回0。
3. 只需检查到平方根：因数总是成对出现，一对因数至少有一个不大于平方根。
4. 例如13试除2、3均不能整除，返回1；9在d=3时被整除，返回0。

## 知识点总结

- num%d==0：余数为0表示d是num的因数。
- d<=num/d：等价于d*d<=num，但不会因为d*d溢出而出错。
- 函数返回0或1：main中的if把0当作假，非0当作真。

## 易错点

- 1、0和负数都不是素数，必须在试除前排除。
- 不能把找到一个不能整除的d就当作素数，要等全部候选因数检查完。

## 相似题目

- [【函数】F7.08 偶数分解【★】](ch03-function-08.md)：共同练习：素数、试除法、函数。
- [8.34 统计素数【★★】](ch05-array-34.md)：共同练习：素数。

## 再练一个用例

1是素数判定的常见边界。。

**输入：**

```text
1
```

**输出：**

```text
Non Prime
```

---

[上一题：【函数】F7.02 数的合并【★】](ch03-function-02.md) · [下一题：【函数】F7.04 求阶乘【★】](ch03-function-04.md)
