# 10.05 整数分离【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第5题。

## 题目

10.05 整数分离【★★】

【题目描述】

输入一个长度不超过30的字符串，内有数字字符和非数字字符（不包括“-”），找出其中包含的非负整数并输出。

【输入】

一个长度不超过30的字符串，其中不包括“-”。

【输出】

字符串中包含的非负整数，一个一行。如果没有数据，什么都不输出。

例如:

**输入：**

```text
123*456U17960? 302tab5876
```

**输出：**

```text
123
456
17960
302
5876
```

## 解答

```c
#include <stdio.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    char s[33]; read_line(s, sizeof s);
    int i = 0;
    while (s[i]) {
        if (s[i] < '0' || s[i] > '9') { ++i; continue; }
        int begin = i;
        while (s[i] >= '0' && s[i] <= '9') ++i;
        int end = i;
        while (begin + 1 < end && s[begin] == '0') ++begin;
        for (int j = begin; j < end; ++j) putchar(s[j]);
        putchar('\n');
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-05.c)

## 讲解

1. 遇到非数字直接前进；遇到数字则记下这一段的开头。
2. 一直前进到非数字或串尾，就确定一个完整整数的范围。
3. 例如x0012y000得到两段0012和000，分别去前导零后输出12和0。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 末尾也可能是数字，不能只在遇到分隔符时才处理。
- 每段最多30位，用字符输出避免整数溢出。

## 相似题目

- [10.04 数字提取【★】](ch05-string-04.md)：共同练习：字符串、数字提取。
- [10.13 字母简化【★★★】](ch05-string-13.md)：共同练习：字符串、分段扫描。

## 再练一个用例

检查全零数字段和末尾数字段。。

**输入：**

```text
a000b0012
```

**输出：**

```text
0
12
```

---

[上一题：10.04 数字提取【★】](ch05-string-04.md) · [下一题：10.06 Your Ride Is Here【★★】](ch05-string-06.md)
