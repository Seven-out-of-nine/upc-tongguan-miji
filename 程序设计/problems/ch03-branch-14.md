# \[5.14\]翻译星期几★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第14题。

## 题目

描述

输入用数字(1--7)表示的星期几，输出星期几的英文表示，输入的数字有误，输出单词"Error"。

输入

输入任意一个整型数（int）

输出

对应星期的英文单词，（开头字母大写）

例如:

**输入：**

```text
1
```

**输出：**

```text
Monday
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    int day;
    scanf("%d", &day);
    switch (day) {
        case 1: puts("Monday"); break;
        case 2: puts("Tuesday"); break;
        case 3: puts("Wednesday"); break;
        case 4: puts("Thursday"); break;
        case 5: puts("Friday"); break;
        case 6: puts("Saturday"); break;
        case 7: puts("Sunday"); break;
        default: puts("Error");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-14.c)

## 讲解

1. 输入的1到7各对应一个固定的英文星期名。
2. switch查找与day相同的case，输出对应名称后用break退出。
3. 例如day=1输出Monday；day=8找不到对应case，进入default输出Error。

## 知识点总结

- switch/case：适合将一个整数的若干固定取值映射为不同结果。
- break：结束switch，防止继续执行下一个case。
- default：所有case都不匹配时执行，本题用于处理错误数字。

## 易错点

- 英文拼写、首字母大写要准确，尤其Wednesday、Thursday。
- 漏写break可能一次输出多个星期名。

## 相似题目

- [\[5.19\]简易计算器★★](ch03-branch-19.md)：共同练习：switch。
- [\[5.23\]小明赴约会★](ch03-branch-23.md)：共同练习：条件分支。
- [\[5.12\]判断某年某月的天数★★](ch03-branch-12.md)：共同练习：条件分支。

## 再练一个用例

星期日。

**输入：**

```text
7
```

**输出：**

```text
Sunday
```

---

[上一题：\[5.13\]通信系统的建设费用问题★★](ch03-branch-13.md) · [下一题：\[5.15\]一共跑了几天操★★](ch03-branch-15.md)
