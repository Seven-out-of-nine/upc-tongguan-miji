# 10.25 相同的字符串【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第25题。

## 题目

【题目描述】

在一个字符串王国里生活着许许多多的字符串，如：abcde、adfsddf、dss等等。有一天，国王要来一次人口大普查，主要是想统计在他的王国里究竟有多少对双胞胎或多胞胎（如果两串字符串相同，它们就被认为是双胞胎，如果是多串相同的话即是多胞胎）

【输入】

有多行。第1行一个正整数n，表示有n串字符串，(n&lt;=100)。接下来有n行，每行一串字符串(字符串长度不超过20，不含空格)。

【输出】

一个整数，表示双胞胎或多胞胎的对数

例如:

**输入：**

```text
8
apple
dog
apple
orange
apple
bird
orange
cat
```

**输出：**

```text
2
```

### 题目与实现说明

- 题干“对数”措辞容易歧义。按样例统计出现次数不少于2的不同字符串种类，而不是所有相同下标对的数量。

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int n, answer = 0; char a[100][21]; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%20s", a[i]);
    for (int i = 0; i < n; ++i) {
        int earlier = 0, count = 0;
        for (int j = 0; j < i; ++j) if (strcmp(a[i], a[j]) == 0) earlier = 1;
        if (earlier) continue;
        for (int j = i; j < n; ++j) if (strcmp(a[i], a[j]) == 0) ++count;
        if (count >= 2) ++answer;
    }
    printf("%d\n", answer); return 0;
}
```

[下载完整源码](../solutions/ch05-string-25.c)

## 讲解

1. 每种字符串只在首次出现的位置统计一次。
2. 先查看前面有没有相同串，有则跳过；没有则统计该内容的总出现次数。
3. 出现至少两次就把答案加1。例如apple出现3次、orange出现2次，共2种重复内容，答案为2。

## 知识点总结

- 二维char数组：a[i]保存第i个字符串。
- strcmp(... )==0：判断两个字符串的全部内容相同。
- continue：已经统计过的种类不再重复计算。

## 易错点

- 样例说明统计重复字符串的种类数，不能计算C(次数,2)。

## 相似题目

- [10.26 独一无二的字符串【★★】](ch05-string-26.md)：共同练习：字符串、频率统计。
- [10.34 小明去过的城市【★】](ch05-string-34.md)：共同练习：字符串、频率统计。

## 再练一个用例

检查三胞胎也只算一种。。

**输入：**

```text
5
x
x
x
y
y
```

**输出：**

```text
2
```

---

[上一题：10.24 字符串比较大小【★】](ch05-string-24.md) · [下一题：10.26 独一无二的字符串【★★】](ch05-string-26.md)
