# TJ10.07 字符串王国的种族★★

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第47题。

## 题目

TJ10.07 字符串王国的种族★★

【题目描述】

在一个字符串王国里生活着许许多多的字符串，如:abcde、adfsddf、dss等等。当然他们也同人类一样有许许多多的种族。如果两个字符串第一个字母相同（区分大小写），那么他们就拥有共同的祖先，便认为他们是同一族的。现在给你一份王国所有成员的名单，请你找出王国里有多少个种族！

【输入】

第一行输入一个整数n，表示有n个字符串(n&lt;=100)。

接下来n行每行输入一个字符串(长度不超过100，仅由英文字母组成不含空格)。

【输出】

输出种族的个数

例如:

**输入：**

```text
5
saf
dfdsf
fghhgfh
ffgf
dfdsfbg
```

**输出：**

```text
3
```

## 解答

```c
#include <stdio.h>

int main(void) {
    int n, seen[256] = {0}, answer = 0; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s[101]; scanf("%100s", s);
        unsigned char first = (unsigned char)s[0];
        if (!seen[first]) { seen[first] = 1; ++answer; }
    }
    printf("%d\n", answer); return 0;
}
```

[下载完整源码](../solutions/ch05-string-47.c)

## 讲解

1. 种族只由首字母决定，后面的字符不用参与判断。
2. 记录每种首字母是否出现，第一次看到它时种族数加1。
3. 例如apple、ant、Bob、bee共有a、B、b三个首字母，所以是3族。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 大小写区分，B和b属于不同种族。

## 相似题目

- [10.18 删除重复字符【★★】](ch05-string-18.md)：共同练习：字符串、去重。
- [10.41 GLB串升级版【★★】](ch05-string-41.md)：共同练习：字符串、集合。

## 再练一个用例

检查大小写分族。。

**输入：**

```text
3
Apple
ant
Another
```

**输出：**

```text
2
```

---

[上一题：TJ10.02 A==B？★★](ch05-string-46.md) · [下一题：TJ10.10 首字母大写★★](ch05-string-48.md)
