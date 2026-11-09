# 10.15 安全密码【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第15题。

## 题目

【题目描述】

随着电子设备的广泛运用，密码也渐渐融入每个人的生活。保护好密码，不仅关系到个人隐私，更关系到个人的财产和安全。一个安全的密码，最好由大小写字母、数字或符号组成。包含越多种类的字符，其安全性就越高。同时密码还需要有一定的长度，通常至少要由六个以上的字符组成。

并不是每个人都喜欢这样复杂的密码，很多人在设置密码的时候，喜欢使用自己的名字或者生日，但这是很大的安全隐患。

小林正在设计一个网络交易系统，为了保证用户的密码安全，他需要一个程序，判断用户自己设置的密码是否安全，如果不安全，则给出提示。现在他向你求助，请你帮忙设计一个程序来解决这个问题。按照以下的规则来判断密码是否安全：

l 如果密码长度小于 6 位，则不安全

l 如果组成密码的字符只有一类，则不安全

l 如果组成密码的字符有两类，则为中度安全

l 如果组成密码的字符有三类或以上，则为安全

通常，可以认为数字、大写字母、小写字母和其它符号为四类不同的字符。

【输入】

有多行。第一行是一个整数 N，表明后面有多少组密码。随后的 N 行输入包括 N 个密码，每个密码的长度均小于 80个字符。

【输出】

针对每一个密码判断并输出它是否安全。对于不安全的密码输出 "Not Safe"，对于中度安全的密码输出 "Medium Safe"，对于安全的密码输出 "Safe"

例如:

**输入：**

```text
10
abcDEF
ABC
qw
`
ABCDEFGHIJKLMNOPQRST
12345678901234567890
          1aB
1 B
a X   
qwe123%^&ABC
```

**输出：**

```text
Medium Safe
Not Safe
Not Safe
Not Safe
Not Safe
Not Safe
Safe
Not Safe
Safe
Safe
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
    int n, ch; scanf("%d", &n);
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    while (n--) {
        char s[83]; read_line(s, sizeof s);
        int kinds[4] = {0}, len = 0;
        while (s[len]) {
            char c = s[len++];
            if (c >= '0' && c <= '9') kinds[0] = 1;
            else if (c >= 'A' && c <= 'Z') kinds[1] = 1;
            else if (c >= 'a' && c <= 'z') kinds[2] = 1;
            else kinds[3] = 1;
        }
        int total = kinds[0] + kinds[1] + kinds[2] + kinds[3];
        if (len < 6 || total <= 1) puts("Not Safe");
        else if (total == 2) puts("Medium Safe"); else puts("Safe");
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-string-15.c)

## 讲解

1. 每个密码整行读入，前后空格也是密码字符。
2. 四个标记记录数字、大写、小写、其他符号是否出现，出现多次也只记一种。
3. 例如abcDEF长度6且有两类，输出Medium Safe；a1B!xx有四类，输出Safe。
4. 先检查长度不足6，再按字符种类数判断等级。

## 知识点总结

- kinds[4]={0}：每个密码重新清空四类标记。
- else分支：空格等非数字非字母都归入其他符号。
- len++：扫描时同步累计密码长度。

## 易错点

- 不能用%s，否则含空格的密码被截断。
- 长度不足6时，即使四类齐全也不安全。

## 相似题目

- [20108 胡恼的邮箱密码](quiz5-06.md)：共同练习：字符串、分类统计。
- [10.14 合法标识符【★★】](ch05-string-14.md)：共同练习：字符串。

## 再练一个用例

检查长度门槛与两类、四类密码。。

**输入：**

```text
3
a1B!x
abc123
a1B!xx
```

**输出：**

```text
Not Safe
Medium Safe
Safe
```

---

[上一题：10.14 合法标识符【★★】](ch05-string-14.md) · [下一题：10.16 删除指定字符【★】](ch05-string-16.md)
