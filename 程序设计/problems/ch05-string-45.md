# 10.45 库函数技巧【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第45题。

## 题目

【题目描述】

把字符串中所有的字符前移一个位置，串中的第一个字符移到最后。例如原有的字符串为： Mn.123xyZ ，则调用该函数后，串中的内容为： n.123xyZM 。

【输入】

一个字符串（长度小于82）。

【输出】

移动后的字符串。

例如:

**输入：**

```text
Mn.123xyZ
```

**输出：**

```text
n.123xyZM
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
    char s[85]; read_line(s, sizeof s);
    int n = 0; while (s[n]) ++n;
    if (n > 0) {
        char first = s[0];
        for (int i = 0; i + 1 < n; ++i) s[i] = s[i + 1];
        s[n - 1] = first;
    }
    puts(s); return 0;
}
```

[下载完整源码](../solutions/ch05-string-45.c)

## 讲解

1. 先计算串长，空串直接输出。
2. 把原首字符暂存，后面的每个字符向前移动一格。
3. 例如abc先保存a，再移动b、c，末位填a，得到bca。

## 知识点总结

- char first：在覆盖首字符前保留它。
- i+1<n：只移动内容字符，结束符保持在原位置。
- n>0：避免空串访问s[-1]。

## 易错点

- 必须先保存首字符，否则移动后就找不回它。

## 相似题目

- [10.21 字符串合并【★】](ch05-string-21.md)：共同练习：字符串。
- [10.40 镜像文字【★】](ch05-string-40.md)：共同练习：字符串。

## 再练一个用例

检查单字符旋转不变。。

**输入：**

```text
X
```

**输出：**

```text
X
```

---

[上一题：10.44 奇怪的A+B【★★★】](ch05-string-44.md) · [下一题：TJ10.02 A==B？★★](ch05-string-46.md)
