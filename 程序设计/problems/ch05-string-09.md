# 10.09 单词缩写【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第9题。

## 题目

10.09 单词缩写【★★★】

【题目描述】

As we know, we often use a short sequence of characters in place of some words with a very long name. For example, ACM is an abbreviation of "Association for Computing Machinery". Now we are using an acronymic method to get the abbreviation. An acronym is generated from a long name by capitalizing the first letter of every word in the name and concatenating them together. There is an exception: some words are ignored when generating the abbreviation. These words( case insensitive) meet the following rules: 1. The common words "and", "for", and "the". 2. The words with length less than 3, such as "a", "of", "to". Your job is to get the abbreviation of a given string by using the acronymic method.

【Input】

Input starts with an integer T (T &lt;= 100), denoting the number of test cases. Each case contains a line with several words seperated by space(s). The length of each line is less than 100. And you can assume that there is at least one available word for each case.

【Output】

For each case, print the abbreviation of the word.

例如:

**输入：**

```text
5
Online Judge
Association for Computer Machinery
Institute of Electrical and Electronics Engineers
The Lord of the Rings
Qingdao
```

**输出：**

```text
OJ
ACM
IEEE
LR
Q
```

## 解答

```c
#include <stdio.h>
#include <string.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    int t; scanf("%d", &t);
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
    while (t--) {
        char s[103]; read_line(s, sizeof s);
        int i = 0;
        while (s[i]) {
            while (s[i] == ' ') ++i;
            int start = i;
            char word[103]; int n = 0;
            while (s[i] && s[i] != ' ') {
                char c = s[i++];
                word[n++] = c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
            }
            word[n] = '\0';
            if (n >= 3 && strcmp(word,"and") && strcmp(word,"for") && strcmp(word,"the")) {
                char c = s[start];
                putchar(c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c);
            }
        }
        putchar('\n');
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-09.c)

## 讲解

1. 读完组数后吃掉该行剩余换行，再按整行读名字。
2. 跳过连续空格，收集一个单词，并把副本转成小写以判断忽略词。
3. 长度不足3或等于and、for、the的词跳过，其余词输出大写首字母。
4. 例如The Lord of the Rings留下Lord和Rings，得到LR。

## 知识点总结

- **strcmp比较C字符串**：<string.h>中的strcmp(a,b)比较两串内容：返回0表示相等，负数表示a较小，正数表示a较大。不能把返回正数理解为一定等于1，也不能用a==b代替内容比较。
- **混合读数值与整行文本**：scanf读取组数后，行末换行通常仍留在输入流中。先用getchar读到'\n'或EOF，再用fgets读取下一整行，避免把残留换行误读为第一个空密码或空名字。

## 易错点

- 忽略词不区分大小写，必须先统一大小写。
- 多个空格不能产生空单词首字母。

## 相似题目

- [10.12 单词统计【★】](ch05-string-12.md)：共同练习：字符串、单词处理。
- [TJ10.10 首字母大写★★](ch05-string-48.md)：共同练习：字符串、单词处理。

## 再练一个用例

检查忽略词大小写和多空格。。

**输入：**

```text
1
tHE  art of CODE and fun
```

**输出：**

```text
ACF
```

---

[上一题：10.08 单词译码【★★】](ch05-string-08.md) · [下一题：10.10 字符出现的次数【★】](ch05-string-10.md)
