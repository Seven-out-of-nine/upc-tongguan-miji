# 10.19 字符串删除【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第19题。

## 题目

【题目描述】

删除字符串指定位置字符后的m个连续字符（包括指定位置的字符）。

【输入】

有两行。第一行为一个长度不超过80的字符串。第二行为两个整数n和m，分别代表字符串的第n个字符(非下标)和要删除m个连续字符。m+n＜字符串的长度。

【输出】

处理后的字符串。

提示：用string会非常简单。

例如:

**输入：**

```text
I love movie
7 6
```

**输出：**

```text
I love
```

### 题目与实现说明

- 原题约束“m+n<字符串长度”与样例不符；按样例执行从第n个字符开始删除m个字符，扫到串尾即结束。

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
    char s[83]; read_line(s, sizeof s);
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; s[i]; ++i) if (i < n - 1 || i >= n - 1 + m) putchar(s[i]);
    putchar('\n'); return 0;
}
```

[下载完整源码](../solutions/ch05-string-19.c)

## 讲解

1. 输入位置n从1数，而数组下标从0数，删除起点为n-1。
2. 删除区间为[n-1,n-1+m)，只输出该区间以外的字符。
3. 例如abcdef从第2个删除3个，即删bcd，剩aef。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 删除包含第n个字符本身，起点不能写成下标n。

## 相似题目

- [10.16 删除指定字符【★】](ch05-string-16.md)：共同练习：字符串。
- [10.23 指定位置插入字符串【★★】](ch05-string-23.md)：共同练习：字符串。

## 再练一个用例

检查1起始位置与删除长度。。

**输入：**

```text
abcdef
2 3
```

**输出：**

```text
aef
```

---

[上一题：10.18 删除重复字符【★★】](ch05-string-18.md) · [下一题：10.20 索马里海盗【★★★】](ch05-string-20.md)
