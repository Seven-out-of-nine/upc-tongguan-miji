# 10.10 字符出现的次数【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第10题。

## 题目

10.10 字符出现的次数【★】

【题目描述】

从键盘输入一个字符串（长度小于等于1000），再输入一个特定字符ch，判断ch在字符串中的出现次数。

【输入】

共两行。第1行为一个字符串，第2行为一个特定字符ch。

【输出】

ch在字符串中的出现次数。

例如:

**输入：**

```text
THIS IS A TEST
I
```

**输出：**

```text
2
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
    char s[1003]; read_line(s, sizeof s);
    int ch = getchar(), count = 0;
    for (int i = 0; s[i]; ++i) if (s[i] == ch) ++count;
    printf("%d\n", count); return 0;
}
```

[下载完整源码](../solutions/ch05-string-10.c)

## 讲解

1. 先读取第一行文本，再读取第二行的目标字符。
2. 从第一个字符扫描到字符串结束，每相等一次就将count加1。
3. 例如a a中的空格作为目标时，结果是1。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 目标也可能是空格，不宜用跳过空白的scanf(" %c")。

## 相似题目

- [10.11 字符出现的频率【★】](ch05-string-11.md)：共同练习：字符串。
- [10.30 字符第一次出现的位置【★】](ch05-string-30.md)：共同练习：字符串。

## 再练一个用例

验证把空格作为目标字符。。

**输入：**

```text
a a a
```

**输出：**

```text
2
```

---

[上一题：10.09 单词缩写【★★★】](ch05-string-09.md) · [下一题：10.11 字符出现的频率【★】](ch05-string-11.md)
