# 10.44 奇怪的A+B【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第44题。

## 题目

【题目描述】

小明做过很多版本的A+B，可是这次的A+B有点棘手。这次的问题是告诉你一个表达式满足 A + B =，让你求出它的值，棘手的地方在于A和B （ A和B的值小于10000 ） 都是用英文表示的，就是用英文单词表示A和B每位上的数，最后求出它们的和。

【输入】

第一个数T（ 0 &lt;T&lt;= 100 ）表示测试数据的组数。每组测试数据有一行，每行满足A + B = ，A和B都是由英文单词组成，单词由空格隔开。

【输出】

对于每组测试数据输出一个整数，表示由A，B所表示的数字的和。

例如:

**输入：**

```text
2
seven four + nine =
eight + two four five =
```

**输出：**

```text
83
253
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int digit(const char word[]) {
    const char *names[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i < 10; ++i) if (strcmp(word, names[i]) == 0) return i;
    return -1;
}
int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char word[16]; int a = 0, b = 0, second = 0;
        while (scanf("%15s", word) == 1 && strcmp(word, "=") != 0) {
            if (strcmp(word, "+") == 0) second = 1;
            else if (!second) a = a * 10 + digit(word);
            else b = b * 10 + digit(word);
        }
        printf("%d\n", a + b);
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-44.c)

## 讲解

1. 用表把zero到nine对应到数字0到9。
2. 逐词读取，遇到+之前拼接到a，之后拼接到b，遇到=结束当前组。
3. 例如seven four先得到7，再得到7×10+4=74，nine得到9，输出83。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 每个英文词代表一个数字位，并非英文整数读法。

## 相似题目

- [10.04 数字提取【★】](ch05-string-04.md)：共同练习：字符串、数字提取。
- [10.37 营业额【★★★】](ch05-string-37.md)：共同练习：字符串。

## 再练一个用例

检查zero和多位拼接。。

**输入：**

```text
1
zero + one zero =
```

**输出：**

```text
10
```

---

[上一题：10.43 垂直柱状图【★★★】](ch05-string-43.md) · [下一题：10.45 库函数技巧【★】](ch05-string-45.md)
