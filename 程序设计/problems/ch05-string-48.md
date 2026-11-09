# TJ10.10 首字母大写★★

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第48题。

## 题目

TJ10.10 首字母大写★★

【题目描述】

对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\\t')、回车符('\\r')、换行符('\\n')。

【输入】

一行待处理的字符串（长度小于80）。

【输出】

一行转换后的字符串。

例如:

**输入：**

```text
if so, You already
```

**输出：**

```text
If So, You Already
```

## 解答

```c
#include <stdio.h>
#include <ctype.h>

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
    int start = 1;
    for (int i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (isspace(c)) start = 1;
        else {
            if (start && c >= 'a' && c <= 'z') s[i] = c - 'a' + 'A';
            start = 0;
        }
    }
    puts(s); return 0;
}
```

[下载完整源码](../solutions/ch05-string-48.c)

## 讲解

1. start表示下一个非空白字符是否位于单词开头，初始为真。
2. 遇空白就重新等待新单词；遇非空白，若是词首小写字母就改大写，然后清除start。
3. 例如if so, You得到If So, You，逗号和已有大写不改变。

## 知识点总结

- **ctype字符分类函数**：<ctype.h>中的isspace(c)识别空格、制表符、回车、换行等空白，而不是只识别' '。这类函数的实参必须是EOF或能表示为unsigned char的值，所以先把普通char转成unsigned char再传入，避免负字符值带来的未定义行为。

## 易错点

- 只修改词首小写字母，不能把整个词都改大写。
- 标点不是空白，因此单词内部标点不会另起一个词。

## 相似题目

- [10.03 字符变换【★】](ch05-string-03.md)：共同练习：字符串、字符转换。
- [10.09 单词缩写【★★★】](ch05-string-09.md)：共同练习：字符串、单词处理。

## 再练一个用例

检查开头空格和制表符分词。。

**输入：**

```text
  hello	world
```

**输出：**

```text
  Hello	World
```

---

[上一题：TJ10.07 字符串王国的种族★★](ch05-string-47.md) · [下一题：TJ10.11 反序输出英文单词★](ch05-string-49.md)
