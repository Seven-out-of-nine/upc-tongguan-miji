# 10.18 删除重复字符【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第18题。

## 题目

【题目描述】

输入一个长度不超过 100 的字符串，删除串中的重复字符。例如：输入的字符串为abacaeedabcdcd，删除重复字符串后为abced。

【输入】

一个长度不超过100个字符。

【输出】

删除重复字符后的字符串，保留原来的顺序。

例如:

**输入：**

```text
abacaeedabcd
```

**输出：**

```text
abced
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
    char s[103]; int seen[256] = {0}; read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (!seen[c]) { putchar(c); seen[c] = 1; }
    }
    putchar('\n'); return 0;
}
```

[下载完整源码](../solutions/ch05-string-18.c)

## 讲解

1. 用seen记录每一种字符是否已经输出。
2. 按原顺序扫描，第一次遇到时输出并标记，之后再遇到就跳过。
3. 例如abaca依次保留a、b、c，最后的a已经出现过，不再输出。

## 知识点总结

- seen[256]：为一个字节的每种取值准备一个标记。
- unsigned char：保证用于下标的字符值非负。
- !seen[c]：标记为0时表示首次遇到。

## 易错点

- 保留首次出现的顺序，不能排序后去重。

## 相似题目

- [10.13 字母简化【★★★】](ch05-string-13.md)：共同练习：字符串。
- [TJ10.07 字符串王国的种族★★](ch05-string-47.md)：共同练习：字符串、去重。

## 再练一个用例

检查空格也作为字符去重。。

**输入：**

```text
ab ba
```

**输出：**

```text
ab
```

---

[上一题：10.17 删除指定字符串【★★】](ch05-string-17.md) · [下一题：10.19 字符串删除【★】](ch05-string-19.md)
