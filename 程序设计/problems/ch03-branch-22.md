# \[5.22\]体型判断★★★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第22题。

## 题目

**描述**

体指数t=体重w/\[（身高h）的平方（w单位为千克，h单位为米）

当t&lt;18时为低体重（di） ， 当18&lt;=t&lt;=25时为正常体重（zheng）， 当25&lt;t&lt;=27时为超重体重（chao） ，t&gt;27时为肥胖（pang）。

输入一组体重和身高，输出他的体型。体型用字母代替。

**输入**

体重 身高。

**输出**

体型。

例如:

**输入：**

```text
70 1.8
```

**输出：**

```text
zheng
```

### 题目与实现说明

- 这些分类阈值是本编程练习给定的规则，本页面只讲按规则分类的程序写法。

## 解答

```c
#include <stdio.h>

int main(void)
{
    double weight, height;
    scanf("%lf %lf", &weight, &height);
    double index = weight / (height * height);
    if (index < 18) puts("di");
    else if (index <= 25) puts("zheng");
    else if (index <= 27) puts("chao");
    else puts("pang");
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-22.c)

## 讲解

1. 按输入顺序保存体重weight和身高height，用weight/(height*height)计算题目定义的指数。
2. 从小到大按18、25、27分界：低于18为di，到25为zheng，到27为chao，其余为pang。
3. 例如70/(1.8*1.8)约21.60，落在18到25之间，因此输出zheng。

## 知识点总结

- double：身高以米为单位，常常含小数，指数也不能用整数保存。
- 括号乘方：height*height表示身高平方，分母必须整体放在括号里。
- 互斥区间：第二个分支已经知道index>=18，只需再检查<=25。

## 易错点

- 25属于zheng，27属于chao，不要在边界使用错误的不等号。
- 有效输入中身高应大于0，单位必须为米而不是厘米。

## 相似题目

- [\[5.20\]判断成绩区间★★](ch03-branch-20.md)：共同练习：条件分支、分段函数。
- [\[5.05\]邮局包裹邮寄★★★](ch03-branch-05.md)：共同练习：条件分支、分段函数。
- [\[4.06\]冰箱的温度★](ch02-19.md)：共同练习：实数运算。

## 再练一个用例

25归正常区间。

**输入：**

```text
25 1
```

**输出：**

```text
zheng
```

---

[上一题：\[5.21\]判断字符类型★★](ch03-branch-21.md) · [下一题：\[5.23\]小明赴约会★](ch03-branch-23.md)
