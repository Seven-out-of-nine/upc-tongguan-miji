# 8.23 寻找非共有数字【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第23题。

## 题目

【题目描述】

给定两个整型数组，要求找出不是两者共有的元素。

【输入】

有两行。第1行先给出正整数n（n≤20），随后是n个整数，其间以空格分隔。第2行先给出正整数m（m≤20），随后是m个整数，其间以空格分隔。

【输出】

仅一行。按照数字出现的顺序输出不是两数组共有的元素，数字间以空格分隔。题目保证至少存在一个这样的数字，同一数字不重复输出。

例如:

**输入：**

```text
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
```

**输出：**

```text
3 5 -15 6 4 1
```

## 解答

```c
#include <stdio.h>

int Contains(const int values[], int n, int target)
{
    for (int i = 0; i < n; ++i)
        if (values[i] == target) return 1;
    return 0;
}

int main(void)
{
    int n, m, first[20], second[20], answer[40], length = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &first[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &second[i]);
    for (int i = 0; i < n; ++i)
        if (!Contains(second, m, first[i]) && !Contains(answer, length, first[i])) answer[length++] = first[i];
    for (int i = 0; i < m; ++i)
        if (!Contains(first, n, second[i]) && !Contains(answer, length, second[i])) answer[length++] = second[i];
    for (int i = 0; i < length; ++i) {
        if (i) putchar(' ');
        printf("%d", answer[i]);
    }
    putchar('\n');
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-23.c)

## 讲解

1. Contains通过逐个比较判断一个数是否在指定数组里，找到返回1，找不到返回0。
2. 按第一个数组原顺序检查：若数字不在第二个数组，也尚未加入答案，就追加它。
3. 再按第二个数组原顺序执行同样检查，这次排除第一个数组中已有的数字。
4. 例如第一组-5 -5 2、第二组2 7，-5只加入一次，2是共有数不加入，最后加入7，输出-5 7。

## 知识点总结

- **数组作为函数参数**：Contains(const int values[],int n,int target)通过数组形参读取调用者传来的元素；数组的有效长度不会自动传入，必须另用n说明，只扫描0到n-1。调用时传数组名，不需要逐项复制到形参。
- **const修饰只读形参**：const int values[]表示函数可以读取values的元素，但不能通过这个形参给元素赋新值。它把“只负责检查、不负责修改”的约定写进接口；这里const限制的是通过形参进行的修改，并不要求原数组本来就是常量。

## 易错点

- 原题数字可为负数，不能直接用数字作小数组下标。
- 不能只排除共有数字，还必须防止同一个非共有数字重复输出。

## 相似题目

- [8.21 顺序查找【★】](ch05-array-21.md)：共同练习：顺序查找、数组。
- [8.22 寻找重复数字【★★】](ch05-array-22.md)：共同练习：去重、数组。

## 再练一个用例

同时检查负数、共有数字和数组内部重复。。

**输入：**

```text
3 -5 -5 2
2 2 7
```

**输出：**

```text
-5 7
```

---

[上一题：8.22 寻找重复数字【★★】](ch05-array-22.md) · [下一题：8.24 二分查找【★★】](ch05-array-24.md)
