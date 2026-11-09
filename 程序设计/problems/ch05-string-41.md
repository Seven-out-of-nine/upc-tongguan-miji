# 10.41 GLB串升级版【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第41题。

## 题目

【题目描述】

只要一个字符串中包含“GLB”（GLB不一定连续，还不区分大小写，甚至连先后顺序都不分哟），高老板就认为这是一个GLB串。现在给你一些字符串，请你帮高老板判断这些字符串是不是GLB串。

【输入】

有多行。第1行是一个整数T，表示T行数据。接下来T行，每行一个字符串（只包括大小写字母），长度小于300。

【输出】

如果是高老板串输出YES，否则输出NO。

例如:

**输入：**

```text
5
GLBSHIGEmaiIPADMINI4detuhao
wobushiGlb
hahaha
GwobuLshihaBhah
LBhahahG
```

**输出：**

```text
YES
YES
NO
YES
YES
```

## 解答

```c
#include <stdio.h>

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        char s[300]; scanf("%299s", s);
        int g = 0, l = 0, b = 0;
        for (int i = 0; s[i]; ++i) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
            if (c == 'G') g = 1;
            if (c == 'L') l = 1;
            if (c == 'B') b = 1;
        }
        puts(g && l && b ? "YES" : "NO");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-41.c)

## 讲解

1. 每个字符串设三个标记，分别记录是否见过G、L、B。
2. 扫描时先把小写字母临时转换为大写，再更新对应标记。
3. 例如bxxLyyg三个标记最后都为1，虽然不连续且逆序，也输出YES。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 本题不要求连续，也不要求G、L、B按固定顺序出现。

## 相似题目

- [10.35 GLB串【★★】](ch05-string-35.md)：共同练习：字符串。
- [10.15 安全密码【★★★】](ch05-string-15.md)：共同练习：字符串。

## 再练一个用例

检查任意次序通过但缺B失败。。

**输入：**

```text
2
bxLg
GGll
```

**输出：**

```text
YES
NO
```

---

[上一题：10.40 镜像文字【★】](ch05-string-40.md) · [下一题：10.42 ISBN号码【★★★】](ch05-string-42.md)
