# 【函数】F7.02 数的合并【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第2题。

## 题目

【函数】F7.02 数的合并【★】

【题目描述】

编写一个能将两个数合并成一个数的函数MergeData，具体合并的方式是：将两个两位数的正整数num1、num2合并形成一个整数放在newnum中，并将num1的十位和个位依次存放在newnum数的十位和千位上，num2的十位和个位依次存放在newnum数的个位和百位上。

【输入】

两个整数num1、num2。

【输出】

合并后的新数据newnum。

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
    int num1, num2, newnum;
    scanf("%d%d", &num1, &num2);
    newnum = MergeData(num1, num2);
    printf("newnum=%d\n", newnum);
    return 0;
}
```

例如:

**输入：**

```text
45 12
```

**输出：**

```text
newnum=5241
```

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
int MergeData(int num1, int num2)
{
    int a = num1 / 10, b = num1 % 10;
    int c = num2 / 10, d = num2 % 10;
    return b * 1000 + d * 100 + a * 10 + c;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

int MergeData(int num1, int num2)
{
    int a = num1 / 10, b = num1 % 10;
    int c = num2 / 10, d = num2 % 10;
    return b * 1000 + d * 100 + a * 10 + c;
}

int main()
{
    int num1, num2, newnum;
    scanf("%d%d", &num1, &num2);
    newnum = MergeData(num1, num2);
    printf("newnum=%d\n", newnum);
    return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-02.c)

## 讲解

1. 把num1拆成十位a、个位b，把num2拆成十位c、个位d。
2. 按题意，新数从千位到个位依次是b、d、a、c，分别乘1000、100、10、1再相加。
3. 例如45和12拆成4、5、1、2，组成5000+200+40+1=5241。

## 知识点总结

- 整数除法/：45/10得到4，去掉个位。
- 取余%：45%10得到5，用于取得个位。
- return表达式：各位乘位权再相加，返回一个整数，而不是输出四个字符。

## 易错点

- 不是把45和12直接拼成4512；必须按指定位置重新排列。
- 个位若是0，新数最前面的0不会作为整数的一部分输出。

## 相似题目

- [\[5.10\] 四位数拆分★](ch03-branch-10.md)：可对照练习：数字拆分、条件分支，比较输入、处理步骤和输出的变化。
- [【函数】F7.07 长整型截短【★★】](ch03-function-07.md)：共同练习：数位拆分、函数。

## 再练一个用例

检验两个个位为0时整数不会保留前导零。。

**输入：**

```text
10 20
```

**输出：**

```text
newnum=12
```

---

[上一题：【函数】F7.01求最大值【★】](ch03-function-01.md) · [下一题：【函数】F7.03 素数的判断【★】](ch03-function-03.md)
