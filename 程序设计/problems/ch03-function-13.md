# 【函数】F7.13富翁与骗子【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第13题。

## 题目

【函数】F7.13富翁与骗子【★★】

【题目描述】

据说有个智商不高的富翁和一个智商较高的骗子。有一天骗子对富翁说：“我搞了一个基金会，你将短期不用的富余资金存到我这里吧。第一天你只需要存入一元，第二天存入两元，以此类推，以后每天存入的资金是前一天的2倍，直到若干天期满为止。与此同时，你可以每天最多支取一笔价钱不菲的金额（先记在账上，合约到期后一次结清。例如每天最多取1万，10天后账单最多就是10万）。”俩人按照上述要求立字据，合约执行若干天后结束，到时两人互不相欠。

现要求编写两个函数Deposit()和Withdraw()分别计算富翁的存入和支取金额，并编写程序调用这两个函数判断：根据富翁每天最多支取的金额，（1）合约至少执行多少天骗子才能骗到钱？（2）该天骗子骗了多少钱？

【输入】

输入有多行。第一行输入一个整数n，表示有n行测试数据。以下有n行数据，每行数据表示富翁每天可以支取的最大金额数amount（1&lt;=amount&lt;=1000000），单位为元。

【输出】

输出有n行。每行两个数据，第1个数据表示合约至少执行多少天骗子才能骗到钱，第2个数据表示该天骗子骗的钱数。

预设代码

前置代码

```text
#include <iostream>
#include <cstdio>
using namespace std;
```

后置代码

```text
int main()
{
    int n,i,day;
    int amount,dpt,wd;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&amount);
        for(day=1;; day++)
        {
            dpt=Deposit(day);
            wd=Withdraw(day,amount);
            if(dpt-wd>0)
            {
                printf("%d天骗取现金%d元\n",day,dpt-wd);
                break;
            }
        }
    }
    return 0;
}
```

例如:

**输入：**

```text
2
300000
400000
```

**输出：**

```text
23天骗取现金1488607元
24天骗取现金7177215元
```

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int Deposit(int day)
{
    int total = 0, daily = 1;
    for (int i = 1; i <= day; ++i) {
        total += daily;
        if (i < day) daily *= 2;
    }
    return total;
}

int Withdraw(int day, int amount)
{
    return day * amount;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int Deposit(int day)
{
    int total = 0, daily = 1;
    for (int i = 1; i <= day; ++i) {
        total += daily;
        if (i < day) daily *= 2;
    }
    return total;
}

int Withdraw(int day, int amount)
{
    return day * amount;
}

int main()
{
    int n,i,day;
    int amount,dpt,wd;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&amount);
        for(day=1;; day++)
        {
            dpt=Deposit(day);
            wd=Withdraw(day,amount);
            if(dpt-wd>0)
            {
                printf("%d天骗取现金%d元\n",day,dpt-wd);
                break;
            }
        }
    }
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-13.c)

## 讲解

1. Deposit(day)累计第1天1元、第2天2元、以后每天翻倍的存款；这是累计金额，不是当天金额。
2. Withdraw(day,amount)计算每天最多支取amount元，day天一共day*amount元。
3. 原main从第1天向后试，第一次出现存款大于支取额的日期就是骗子开始获利的最早日期。
4. 例如每天支取1元，第1天双方都是1元；第2天存入共3元、支取共2元，骗子获利1元。

## 知识点总结

- 两个函数分工：Deposit负责累加倍增项，Withdraw负责乘法，main负责比较与输出。
- for循环：daily保存当天存款，total保存截至当天的累计存款。
- if(dpt-wd>0)：必须严格大于0，收支相等还没有骗到钱。

## 易错点

- 不要只比较当天存款和当天取款，需比较合约累计金额。
- 在amount≤1000000的范围，最迟第25天开始获利，int足以保存这些金额。

## 相似题目

- [【函数】F7.04 求阶乘【★】](ch03-function-04.md)：共同练习：函数。
- [8.09 Box of Brick【★★】](ch05-array-09.md)：共同练习：累加。

## 再练一个用例

最小每日支取额，首日相等不能算获利。。

**输入：**

```text
1
1
```

**输出：**

```text
2天骗取现金1元
```

---

[上一题：【函数】F7.12 求数列的第N项【★】](ch03-function-12.md)
