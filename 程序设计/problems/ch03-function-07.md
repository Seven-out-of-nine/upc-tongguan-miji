# 【函数】F7.07 长整型截短【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第7题。

## 题目

【函数】F7.07 长整型截短【★★】

【题目描述】

编写一个函数Fun，其功能是：将形参n中，各位上为偶数的数取出，并按原来从高位到低位的顺序组成一个新的数，并作为函数值返回。

【输入】

一个整数n。

【输出】

按照要求形成的新整数。

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
    int  n;
    scanf("%d",&n);
    printf("The result is: %d\n",Fun(n));
    return 0;
}
```

例如:

**输入：**

```text
27638496
```

**输出：**

```text
The result is: 26846
```

### 题目与实现说明

- 题干没有说明负数的处理，程序按绝对值筛选数位；无可保留数位时返回0。

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int Fun(int n)
{
    long long value = n;
    if (value < 0) value = -value;
    long long place = 1;
    while (value / place >= 10) place *= 10;
    long long result = 0;
    while (place > 0) {
        int digit = (int)(value / place);
        if (digit % 2 == 0) result = result * 10 + digit;
        value %= place;
        place /= 10;
    }
    return (int)result;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int Fun(int n)
{
    long long value = n;
    if (value < 0) value = -value;
    long long place = 1;
    while (value / place >= 10) place *= 10;
    long long result = 0;
    while (place > 0) {
        int digit = (int)(value / place);
        if (digit % 2 == 0) result = result * 10 + digit;
        value %= place;
        place /= 10;
    }
    return (int)result;
}

int main()
{
    int  n;
    scanf("%d",&n);
    printf("The result is: %d\n",Fun(n));
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-07.c)

## 讲解

1. 先找到最高位的位权place，例如2763对应1000，再从左往右取数位。
2. digit=value/place得到当前最高位；如果digit为偶数，就用result*10+digit接到答案后面。
3. value%=place删除已处理的最高位，place/=10移向下一位，直到place为0。
4. 例如27638496依次保留2、6、8、4、6，得到26846；0也属于偶数数字。

## 知识点总结

- long long：先把int转为更宽的整数，再取负，避免最小int直接取负溢出。
- result*10+digit：十进制数每追加一位，旧数左移一位再加新数字。
- while(place>0)：保证除数不是0，逐位扫描结束后停止。

## 易错点

- 筛的是数位的奇偶性，不能判断整个n是否为偶数。
- 最高位权只能乘到需要的位置，不能额外乘10导致int溢出。

## 相似题目

- [【函数】F7.02 数的合并【★】](ch03-function-02.md)：共同练习：数位拆分、函数。
- [8.26 各位数字组最大数【★★】](ch05-array-26.md)：共同练习：数位拆分。

## 再练一个用例

零也是偶数，开头的0省略，其余0应保留。。

**输入：**

```text
102030
```

**输出：**

```text
The result is: 200
```

---

[上一题：【函数】F7.06 浮点数四舍五入【★】](ch03-function-06.md) · [下一题：【函数】F7.08 偶数分解【★】](ch03-function-08.md)
