# 8.37 到底有多远【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第37题。

## 题目

【题目描述】

现在给你一个从小到大排序的集合，定义其中任意两个元素的距离为“它们在集合中的名次（位置）之差的绝对值”。给你集合中的两个元素，请计算距离。

【输入】

有多行。第1行是一个数n（10000≤n≤1000000），代表集合中一共有n个数。接下来一行有n个数。这n个数由小到大排列（所有的数都为整型数据，并且没有相等的数）。第3行是一个数m（5000≤m≤10000），代表询问次数。然后有m行，每行两个数，a，b（a，b保证是集合中的元素，所以请不要考虑a，b不在集合中的特殊情况，a和b最大为2000000）表示询问a，b之间的距离。注意a未必小于b。

【输出】

有m行。每行一个整数，表示每次询问a和b的距离。

例如:

**输入：**

```text
5
1 3 5 6 8
3
1 5
1 6
8 3
```

**输出：**

```text
2
3
3
```

### 题目与实现说明

- 正文给n、m较大的下界，但样例远小于该范围；算法同样支持样例和较小数据。

## 解答

```c
#include <stdio.h>

static int value[1000000];

int FindPosition(int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (value[mid] == target) return mid;
        if (value[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void)
{
    int n, queries;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    scanf("%d", &queries);
    while (queries--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int distance = FindPosition(n, a) - FindPosition(n, b);
        if (distance < 0) distance = -distance;
        printf("%d\n", distance);
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-37.c)

## 讲解

1. 距离的定义是位置差的绝对值，所以先找到a和b各自的下标。
2. 集合已升序且没有重复，使用二分查找，每轮根据中间元素与目标的大小舍弃一半区间。
3. 得到两个下标后相减，若结果为负就取相反数，再输出。
4. 例如1、3、5、6、8中，8的下标4、3的下标1，距离|4-1|=3，不能计算数值差8-3。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 题目询问位置差而非数值差。
- a可能大于b，也可能等于b，都应正确处理绝对值。

## 相似题目

- [8.24 二分查找【★★】](ch05-array-24.md)：共同练习：二分查找、有序数组。
- [8.21 顺序查找【★】](ch05-array-21.md)：可对照练习：顺序查找、数组，比较输入、处理步骤和输出的变化。

## 再练一个用例

逆序询问和相同元素的距离都要正确。。

**输入：**

```text
3
10 20 100
2
100 10
20 20
```

**输出：**

```text
2
0
```

---

[上一题：8.36 百灯熄灭【★★】](ch05-array-36.md) · [下一题：8.38 黑色星期五【★★★】](ch05-array-38.md)
