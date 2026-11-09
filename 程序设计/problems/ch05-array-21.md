# 8.21 顺序查找【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第21题。

## 题目

**【题目描述】**

从输入的n个整数中查找给定的SearchNum（若存在必唯一）。如果找到，输出SearchNum的位置（从0开始数）；如果没有找到，输出“Not Found”。

**【输入】**

有两行。第1行是两个正整数n（n≤20）和SearchNum。第2行是n个整数，数字均不超过基本整型，其间以空格分隔。

**【输出】**

仅一行。如果找到，输出SearchNum的位置（从0开始数）；如果没有找到，输出“Not Found”。

例如:

**输入：**

```text
5 7
3 5 7 1 9
```

**输出：**

```text
2
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    int n, target, value[20], position = -1;
    scanf("%d%d", &n, &target);
    for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
    for (int i = 0; i < n; ++i) {
        if (value[i] == target) { position = i; break; }
    }
    if (position == -1) puts("Not Found");
    else printf("%d\n", position);
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-21.c)

## 讲解

1. position先设为-1，表示目前还没有找到目标。
2. 从下标0到n-1逐个比较，等于target就记录位置并停止寻找。
3. 扫描完后根据position是否仍为-1输出Not Found或找到的下标。
4. 例如3 5 7 1 9中，7位于第3个元素，但从0开始计数，输出2。

## 知识点总结

- **顺序查找与未找到标记**：从第0个有效元素开始逐个比较目标，找到就保存下标并结束。用-1表示未找到，因为合法下标包含0却不含-1；不能用下标值的真假判断是否找到，否则首项位置0会被误判。

## 易错点

- 找到首项时位置为0，不能用if(position)判断是否找到。
- 输出要求从0开始，不要给位置加1。

## 相似题目

- [8.24 二分查找【★★】](ch05-array-24.md)：可对照练习：二分查找、有序数组，比较输入、处理步骤和输出的变化。
- [8.37 到底有多远【★★】](ch05-array-37.md)：可对照练习：二分查找、有序数组，比较输入、处理步骤和输出的变化。

## 再练一个用例

目标不在数组时保留-1标记。。

**输入：**

```text
3 9
1 2 3
```

**输出：**

```text
Not Found
```

---

[上一题：8.20 图像旋转【★★】](ch05-array-20.md) · [下一题：8.22 寻找重复数字【★★】](ch05-array-22.md)
