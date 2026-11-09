# 10.07 YY and YY again【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第7题。

## 题目

10.07 YY and YY again【★★】

【题目描述】

If we define each of the upper case letters a number, that is, 1 for A, 2 for B, 3for C, ... 25 for Y, 26 for Z, we can calculate a mark for any word or sentence.

We believe that 100 points is the full mark, so for those word with a mark larger than 100, we should just ignore that, with a label "INVALID" .Then let's see interesting results:

What is the most important for your success?

HARDWORK? H+A+R+D+W+O+R+K=8+1+18+4+23+15+18+11=98

KNOWLEDGE? K+N+O+W+L+E+D+G+E=11+14+15+23+12+5+4+7+5=96

MONEY? M+O+N+E+Y=13+15+14+5+25=72

LUCK? L+U+C+K=12+21+3+11=47

ATTITUDE! A+T+T+I+T+U+D+E=1+20+20+9+20+21+4+5=100

So just be with good attitude and you will be on your way to success.

【输入】

For each case of the input, it contains a single line. For each line, some characters will appear with maybe some of them being upper case letters. All characters are printable. Each line will have at most 127 characters.

【输出】

You should only pay attention to upper case letters and calculatethe total points. If it is over 100, "INVALID" should be returned. Or you should print the exact point of that.

例如:

**输入：**

```text
DELICIOUS FOOD
```

**输出：**

```text
INVALID
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
    char s[130];
    while (fgets(s, sizeof s, stdin)) {
        int sum = 0;
        for (int i = 0; s[i]; ++i)
            if (s[i] >= 'A' && s[i] <= 'Z') sum += s[i] - 'A' + 1;
        if (sum > 100) puts("INVALID"); else printf("%d\n", sum);
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-07.c)

## 讲解

1. 每读入一行就把该行总分清零。
2. 仅对大写字母累加A=1到Z=26的分值，空格、小写和符号都忽略。
3. 例如AzB只计算A和B，得到3；超过100才输出INVALID。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 题目说每行一组，不能只处理第一行。
- 不要把小写字母也转换后计分。

## 相似题目

- [10.06 Your Ride Is Here【★★】](ch05-string-06.md)：共同练习：字符串。
- [10.11 字符出现的频率【★】](ch05-string-11.md)：共同练习：字符串。

## 再练一个用例

检查超限和忽略非大写字符。。

**输入：**

```text
ZZZZ
Aa1
```

**输出：**

```text
INVALID
1
```

---

[上一题：10.06 Your Ride Is Here【★★】](ch05-string-06.md) · [下一题：10.08 单词译码【★★】](ch05-string-08.md)
