# 3019 读了几页书

[学习首页](../README.md) · [本章目录](../chapters/quiz4/README.md) · [知识点索引](../知识点索引.md)

来源：随堂测验4.html，第1题。

## 题目

3019 读了几页书

Description

ACM俱乐部队员人手一册《算法竞赛入门经典》，大家都特别喜欢读这本书。假设第一天读了x页，以后每天要比前一天多读m页，过了n天之后问ACM队员们各自读了多少页？

Input

输入x、m和n。

Output

输出n天之后ACM队员们各自读了多少页书

例如:

**输入：**

```text
12 6 7
```

**输出：**

```text
210
```

## 解答

```c
#include <stdio.h>

int main(void) {
    long long x, increment, n; scanf("%lld%lld%lld", &x, &increment, &n);
    long long day = x, total = 0;
    for (long long i = 0; i < n; ++i) { total += day; day += increment; }
    printf("%lld\n", total); return 0;
}
```

[下载完整源码](../solutions/quiz4-01.c)

## 讲解

1. day表示当天阅读量，初始为第一天的x页。
2. 每天先把day加入累计页数，再让day增加m，准备下一天。
3. 例如x=12、m=6、n=3，依次累计12、18、24，共54页。

## 知识点总结

- long long：保存天数与累计页数，减小溢出风险。
- for(i=0;i<n;++i)：恰好进行n次每日累计。
- total+=day：把当天页数加入全部已读页数。

## 易错点

- 题目求n天总量，不是只求第n天的阅读量。
- 要先累计再增加，否则第一天会多算m页。

## 相似题目

- [3035 切饼(循环)](quiz4-02.md)：共同练习：循环、累加。
- [随堂2-1 平均分树苗](quiz2-01.md)：可对照练习：整数运算、商和余数，比较输入、处理步骤和输出的变化。

## 再练一个用例

检查只读一天。。

**输入：**

```text
5 2 1
```

**输出：**

```text
5
```

---

[下一题：3035 切饼(循环)](quiz4-02.md)
