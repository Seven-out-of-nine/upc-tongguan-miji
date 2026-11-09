# 20205 夏边整理成绩单

[学习首页](../README.md) · [本章目录](../chapters/quiz6/README.md) · [知识点索引](../知识点索引.md)

来源：随堂测验6.html，第4题。

## 题目

20205 夏边整理成绩单

【题目描述】

夏边是兢兢业业的学习委员，每次考试成绩出来后，他都主动帮助老师整理考试成绩，他的主要任务包括：算出全班所有学生的平均分、最高分和最低分，然后按照成绩从高到低排列出来。夏边以前都是手动的计算，平时小考还可以应付，但是到了期末集中考试，那么多课程他就应付不过来啦！为此，他编写了程序帮助计算，不过，程序还不完整，缺少最关键的函数部分，你来帮他补全吧！

【输入】

输入数据有两行，第一行为一个整数N（0&lt;N&lt;100），表示学生人数；

第二行包含N个整数，以空格分隔，表示每位同学的考试成绩（百分制）

【输出】

包括两行：第一行依次输出班级平均分（精确到小数点后两位）、最高分和最低分，以空格分隔；

第二行按从大到小的顺序输出每个人的成绩，末尾换行。

main函数代码已给出，要求编写函数FunCount，**注意提交代码时只提交该函数！**

【前置代码】

#include &lt;cstdio&gt;

#include &lt;iostream&gt;

【后置代码】

int main()

{

int n,i,max,min;//n学生数

double avg;

scanf("%d",&n);

int a\[n\];

for (i = 0; i &lt; n; i ++)

scanf("%d",&a\[i\]);

avg = FunCount(a,n,&max,&min);

//输出

printf("%.2f %d %d\\n",avg,max,min);

for (i = 0; i &lt; n; i ++)

printf("%d ",a\[i\]);

putchar('\\n');

return 0;

}

例如:

**输入：**

```text
10
90 90 90 90 90 90 90 90 90 90
```

**输出：**

```text
90.00 90 90
90 90 90 90 90 90 90 90 90 90
```

### 题目与实现说明

- 本地版保留原题main的C可变长数组，使用标准C11编译；提交平台时仅提交FunCount函数。原main在成绩行末自带空格，本地版保持一致。

## 解答

平台已给main，只提交下面函数，勿再提交main。

### 平台提交版

```c
double FunCount(int a[], int n, int *max, int *min) {
    int sum = 0;
    *max = *min = a[0];
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] < a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
    return (double)sum / n;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

double FunCount(int a[], int n, int *max, int *min) {
    int sum = 0;
    *max = *min = a[0];
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] < a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
    return (double)sum / n;
}
int main(void) {
    int n,i,max,min;
    double avg;
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n; i ++) scanf("%d",&a[i]);
    avg = FunCount(a,n,&max,&min);
    printf("%.2f %d %d\n",avg,max,min);
    for (i = 0; i < n; i ++) printf("%d ",a[i]);
    putchar('\n');
    return 0;
}
```

</details>

[下载完整源码](../solutions/quiz6-04.c)

## 讲解

1. 函数先累计总分，最高和最低都先设为第一位学生的成绩。
2. 扫描每个成绩，遇到更高或更低者就更新两个通过指针返回的结果。
3. 然后对原数组冒泡排序，相邻较小值向后交换，让成绩从大到小排列。
4. 例如60、100、80得到平均80.00、最高100、最低60，数组改为100、80、60。

## 知识点总结

- int a[]：形参访问原数组，交换会影响main最终输出。
- int *max和*min：通过解引用修改main中的最高、最低变量。
- (double)sum/n：先转浮点，再求带小数平均。
- a[j]<a[j+1]：降序排列时把较大数交换到前面。

## 易错点

- 函数不仅返回平均值，还必须写出最值并修改原数组顺序。
- 最高、最低不能都从0开始，否则最低分可能一直错误为0。

## 相似题目

- [20105 胡恼分苹果](quiz5-02.md)：共同练习：函数、指针。
- [2002 精挑细选的钢管](quiz3-01.md)：可对照练习：多条件比较、最值，比较输入、处理步骤和输出的变化。

## 再练一个用例

检查排序、平均值和指针返回最值。。

**输入：**

```text
3
60 100 80
```

**输出：**

```text
80.00 100 60
100 80 60
```

---

[上一题：20204 夏边的奇偶数之恋](quiz6-03.md) · [下一题：20206 夏边是逃课小王子](quiz6-05.md)
