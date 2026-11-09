# 10.33 上课点名 【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第33题。

## 题目

【题目描述】

小明的老师每次上课前都要点名，但是这样就浪费了老师的上课时间。所以老师让小明来在课前的的时候就点好名。老师给了小明名单，小明只要照着名单点名就好了，是不是很简单啊！

【输入】

有三行。第1行为两个整数m, n（50 &gt;= m &gt;= n）。第2行有m个名字，是小明班上同学的名单。第3行的n个名字是来上课的同学。名字间用空格隔开，名字的长度不超过20个字符。

【输出】

m行，对应名单中每个学生的出勤情况，如果来上课了，输出"YES"，否则输出"NO"。

例如:

**输入：**

```text
3 2
Bob Marry Jam
Bob Jam
```

**输出：**

```text
YES
NO
YES
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int m, n; char all[50][21], present[50][21]; scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%20s", all[i]);
    for (int i = 0; i < n; ++i) scanf("%20s", present[i]);
    for (int i = 0; i < m; ++i) {
        int found = 0;
        for (int j = 0; j < n; ++j) if (strcmp(all[i], present[j]) == 0) found = 1;
        puts(found ? "YES" : "NO");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-33.c)

## 讲解

1. 先保存完整名单，再保存实际到课名单。
2. 依次处理完整名单中的每个人，在到课名单中查找相同名字。
3. 例如Bob、Marry、Jam中到课Bob和Jam，按原名单输出YES、NO、YES。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 输出顺序必须依照完整名单，不能依到课名单。

## 相似题目

- [10.34 小明去过的城市【★】](ch05-string-34.md)：共同练习：字符串、查找。
- [8.21 顺序查找【★】](ch05-array-21.md)：可对照练习：顺序查找、数组，比较输入、处理步骤和输出的变化。

## 再练一个用例

检查没有学生到课。。

**输入：**

```text
2 0
Ann Bob
```

**输出：**

```text
NO
NO
```

---

[上一题：10.32 找第一个只出现一次的字符【★★】](ch05-string-32.md) · [下一题：10.34 小明去过的城市【★】](ch05-string-34.md)
