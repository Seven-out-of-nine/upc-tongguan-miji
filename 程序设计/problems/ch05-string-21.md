# 10.21 字符串合并【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第21题。

## 题目

【题目描述】

按照输入顺序连接2个字符串（单个字符串的长度不超过100），请尝试不使用C/C++语言提供的任何字符串相关的标准库函数。

【输入】

2个字符串，每个字符串以换行符结束。

【输出】

连接好的字符串。

例如:

**输入：**

```text
Hello
UPC
```

**输出：**

```text
HelloUPC
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
    char a[103], b[103], result[201];
    read_line(a, sizeof a); read_line(b, sizeof b);
    int k = 0;
    for (int i = 0; a[i]; ++i) result[k++] = a[i];
    for (int i = 0; b[i]; ++i) result[k++] = b[i];
    result[k] = '\0'; puts(result); return 0;
}
```

[下载完整源码](../solutions/ch05-string-21.c)

## 讲解

1. 读取两行，分别保存到a和b。
2. 用k指向结果的下一个空位，先复制a所有字符，再接着复制b。
3. 例如ab与CD得到abCD，最后补结束符后输出。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 两个输入可能带空格，需要整行读取。
- 连接后的数组必须足够大并补\0。

## 相似题目

- [10.02 带空格的字符串输入输出【★】](ch05-string-02.md)：共同练习：字符串。
- [10.22 字符接龙【★】](ch05-string-22.md)：共同练习：字符串。

## 再练一个用例

检查连接处两个空格均保留。。

**输入：**

```text
a 
 b
```

**输出：**

```text
a  b
```

---

[上一题：10.20 索马里海盗【★★★】](ch05-string-20.md) · [下一题：10.22 字符接龙【★】](ch05-string-22.md)
