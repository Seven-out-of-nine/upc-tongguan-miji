# 10.16 删除指定字符【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第16题。

## 题目

【题目描述】

从字符串s中删除指定的字符c。

【输入】

共2行，第一行为一个字符串s（长度小于80），第二行一个字符c。

【输出】

删除之后的字符串

例如:

**输入：**

```text
turbo c and borland c++
a
```

**输出：**

```text
turbo c nd borlnd c++
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
    char s[83]; read_line(s, sizeof s);
    int c = getchar();
    for (int i = 0; s[i]; ++i) if (s[i] != c) putchar(s[i]);
    putchar('\n'); return 0;
}
```

[下载完整源码](../solutions/ch05-string-16.c)

## 讲解

1. 整行读字符串，再读要删的字符。
2. 扫描原串，仅输出不等于目标字符的字符，就完成稳定过滤。
3. 例如banana删a，依次保留b、n、n，得到bnn。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 要删除所有匹配字符，不能找到第一个就停止。

## 相似题目

- [10.17 删除指定字符串【★★】](ch05-string-17.md)：共同练习：字符串、字符过滤。
- [10.20 索马里海盗【★★★】](ch05-string-20.md)：共同练习：字符串、字符过滤。

## 再练一个用例

检查多处相同字符全部删除。。

**输入：**

```text
banana
a
```

**输出：**

```text
bnn
```

---

[上一题：10.15 安全密码【★★★】](ch05-string-15.md) · [下一题：10.17 删除指定字符串【★★】](ch05-string-17.md)
