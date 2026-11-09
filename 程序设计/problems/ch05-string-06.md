# 10.06 Your Ride Is Here【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第6题。

## 题目

10.06 Your Ride Is Here【★★】

【题目描述】

It is a well-known fact that behind every good comet is a UFO. These UFOs often come to collect loyal supporters from here on Earth. Unfortunately, they only have room to pick up one group of followers on each trip. They do, however, let the groups know ahead of time which will be picked up for each comet by a clever scheme: they pick a name for the comet which, along with the name of the group, can be used to determine if it is a particular group's turn to go (who do you think names the comets?). The details of the matching scheme are given below; your job is to write a program which takes the names of a group and a comet and then determines whether the group should go with the UFO behind that comet.

Both the name of the group and the name of the comet are converted into a number in the following manner: the final number is just the product of all the letters in the name, where "A" is 1 and "Z" is 26. For instance, the group "USACO" would be 21 \* 19 \* 1 \* 3 \* 15 = 17955. If the group's number mod 47 is the same as the comet's number mod 47, then you need to tell the group to get ready! (Remember that "a mod b" is the remainder left over after dividing a by b; 34 mod 10 is 4.)

Write a program which reads in the name of the comet and the name of the group and figures out whether according to the above scheme the names are a match, printing "GO" if they match and "STAY" if not. The names of the groups and the comets will be a string of capital letters with no spaces or punctuation, up to 6 characters long.

【输入】

Line 1:An upper case character string of length 1..6 that is the name of the comet.

Line 2:An upper case character string of length 1..6 that is the name of the group.

【输出】

A single line containing either the word "GO" or the word "STAY".

例如:

**输入：**

```text
COMETQ
HVNGAT
```

**输出：**

```text
GO
```

## 解答

```c
#include <stdio.h>

int value(const char s[]) {
    int result = 1;
    for (int i = 0; s[i]; ++i) result = result * (s[i] - 'A' + 1) % 47;
    return result;
}
int main(void) {
    char a[7], b[7]; scanf("%6s%6s", a, b);
    puts(value(a) == value(b) ? "GO" : "STAY");
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-06.c)

## 讲解

1. 把A到Z分别映射为1到26。
2. 两个名字分别累乘字母值，每乘一次就对47取余。
3. 例如AB的值为1×2=2，BA也是2，因此输出GO。

## 知识点总结

- const char s[]：函数只读取传入名字，不修改字符。
- %47：求余数；每步取余和最后统一取余结果相同。
- ?:：条件成立输出GO，否则输出STAY。

## 易错点

- 乘积从1开始；从0开始会让所有名字都得到0。

## 相似题目

- [10.07 YY and YY again【★★】](ch05-string-07.md)：共同练习：字符串。
- [10.39 身份证的奥秘1【★★】](ch05-string-39.md)：共同练习：字符串。

## 再练一个用例

检查不同余数时不匹配。。

**输入：**

```text
A
Z
```

**输出：**

```text
STAY
```

---

[上一题：10.05 整数分离【★★】](ch05-string-05.md) · [下一题：10.07 YY and YY again【★★】](ch05-string-07.md)
