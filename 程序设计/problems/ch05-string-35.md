# 10.35 GLB串【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第35题。

## 题目

【题目描述】

只要一个字符串中包含大写“GLB”，高老板就认为这是一个GLB串。现在给你一些字符串，请你帮高老板判断这些字符串是不是GLB串。

【输入】

有多行。第1行一个整数T，表示T行数据。接下来有T行，每行一个字符串（只包括大小写字母），长度小于100。

【输出】

如果是GLB串输出YES，否则输出NO。

例如:

**输入：**

```text
3
GLBSHIGEmaiIPADMINI4detuhao
wobushiGlb
hahaha
```

**输出：**

```text
YES
NO
NO
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char s[100]; scanf("%99s", s);
        puts(strstr(s, "GLB") != NULL ? "YES" : "NO");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-35.c)

## 讲解

1. 读取每一组字符串，在其中查找连续的GLB。
2. strstr找到时返回匹配位置，否则返回NULL，据此输出YES或NO。
3. 例如aGLBb包含GLB，而Glb大小写不符，不能通过。

## 知识点总结

- strstr(s,"GLB")：查找完整连续子串。
- NULL：表示没有匹配位置。
- ?:：根据查找结果选出输出文本。

## 易错点

- 本题要求连续且大小写一致，不能与升级版混淆。

## 相似题目

- [10.36 字符串匹配【★★★】](ch05-string-36.md)：共同练习：字符串、子串查找。
- [10.41 GLB串升级版【★★】](ch05-string-41.md)：共同练习：字符串。

## 再练一个用例

检查连续性和大小写限制。。

**输入：**

```text
3
aGLBb
Glb
GxLB
```

**输出：**

```text
YES
NO
NO
```

---

[上一题：10.34 小明去过的城市【★】](ch05-string-34.md) · [下一题：10.36 字符串匹配【★★★】](ch05-string-36.md)
