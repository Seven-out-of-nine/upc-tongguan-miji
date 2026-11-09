# 8.34 统计素数【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第34题。

## 题目

【题目描述】

求出 2 到 n 之间 (含 n)的所有素数。

【输入】

仅一行。一个正整数n（2&lt;n≤10000）。

【输出】

有两行。第1行是一个整数，表示素数的个数。第2行是从小到大的所有素数，数据间以空格分隔。

例如:

**输入：**

```text
10
```

**输出：**

```text
4
2 3 5 7
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    int n, composite[10001] = {0}, count = 0, printed = 0;
    scanf("%d", &n);
    for (int p = 2; p <= n / p; ++p)
        if (!composite[p])
            for (int multiple = p * p; multiple <= n; multiple += p) composite[multiple] = 1;
    for (int value = 2; value <= n; ++value)
        if (!composite[value]) ++count;
    printf("%d\n", count);
    for (int value = 2; value <= n; ++value) {
        if (!composite[value]) {
            if (printed) putchar(' ');
            printf("%d", value); printed = 1;
        }
    }
    putchar('\n');
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-34.c)

## 讲解

1. 先假设2到n都还可能是素数，用composite数组标记已确定的合数。
2. 从2开始，遇到尚未标记的p，把p²、p²+p等倍数全部标为合数；更小的倍数早已被较小因数标记。
3. 只需筛到平方根，因为每个合数至少有一个因数不大于平方根。
4. 例如n=10，标记4、6、8、10和9后，剩下2、3、5、7，共4个；先输出数量，再输出这些数。

## 知识点总结

- **埃拉托斯特尼筛法**：先把2到n都视为待定；遇到尚未标记的p时，把p²、p²+p等倍数标成合数。p²以前的合数倍数已由更小因子处理，故可从p²开始；筛到平方根后，未被标记的数就是全部素数，适合一次求整个区间。

## 易错点

- 0和1不是素数，因此计数和输出都从2开始。
- 不能把p本身标成合数，所以倍数从p*p开始。

## 相似题目

- [【函数】F7.03 素数的判断【★】](ch03-function-03.md)：共同练习：素数。
- [【函数】F7.08 偶数分解【★】](ch03-function-08.md)：共同练习：素数。

## 再练一个用例

上界3本身是素数，不能因循环写<n而漏掉。。

**输入：**

```text
3
```

**输出：**

```text
2
2 3
```

---

[上一题：8.33 门禁系统【★★】](ch05-array-33.md) · [下一题：8.35 南门的树【★★】](ch05-array-35.md)
