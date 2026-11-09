# 10.02 带空格的字符串输入输出【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第2题。

## 题目

10.02 带空格的字符串输入输出【★】

【题目描述】

输入一个字符串，并按照原样输出。

【输入】

一个字符串（不超过80字符）。

【输出】

原样输出。

例如:

**输入：**

```text
Hello UPC
```

**输出：**

```text
Hello UPC
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
    char s[83];
    read_line(s, sizeof s);
    puts(s);
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-02.c)

## 讲解

1. 用fgets读取整行，把空格也保留下来。
2. read_line将行尾换行替换为字符串结束符，避免重复换行。
3. 例如Hello UPC中的空格仍在原处，最后整行输出。

## 知识点总结

- **fgets整行输入与行尾处理**：fgets(s, sizeof s, stdin)最多读取容量减1个字符，并自动补'\0'，可保留行内空格。读到的行尾可能还含'\n'；本题的read_line只删除行尾换行及配对的回车，不删行内部空白。读取失败时要让数组成为空串。

## 易错点

- 不能用%s读取含空格的整行。
- 只去掉行尾换行，不删除输入中有意义的空格。

## 相似题目

- [10.01 不带空格的字符串输入输出【★】](ch05-string-01.md)：共同练习：字符串。
- [10.15 安全密码【★★★】](ch05-string-15.md)：共同练习：字符串。

## 再练一个用例

验证连续空格被保留。。

**输入：**

```text
a  b
```

**输出：**

```text
a  b
```

---

[上一题：10.01 不带空格的字符串输入输出【★】](ch05-string-01.md) · [下一题：10.03 字符变换【★】](ch05-string-03.md)
