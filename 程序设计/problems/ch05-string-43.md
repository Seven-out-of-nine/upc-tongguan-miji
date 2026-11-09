# 10.43 垂直柱状图【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第43题。

## 题目

【题目描述】

从键盘读取一行大写字母（不超过80个字符），然后用柱状图输出每个字符出现的次数。

【输入】

一行字符，由大写字母组成，每行不超过72个字符。

【输出】

由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。

例如:

**输入：**

```text
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG
```

**输出：**

```text
        *                   *                      
        *                   *                      
      * *     *             *     *   * *          
* * * * * * * * * * * * * * * * * *   * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```

### 题目与实现说明

- 题干称仅大写字母，但样例含空格；本解仅统计A到Z，其余字符忽略。按26列固定宽度输出，各列间一空格。

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
    char s[83]; int count[26] = {0}, height = 0;
    read_line(s, sizeof s);
    for (int i = 0; s[i]; ++i) if (s[i] >= 'A' && s[i] <= 'Z') ++count[s[i] - 'A'];
    for (int i = 0; i < 26; ++i) if (count[i] > height) height = count[i];
    for (int row = height; row >= 1; --row) {
        for (int col = 0; col < 26; ++col) {
            if (col) putchar(' ');
            putchar(count[col] >= row ? '*' : ' ');
        }
        putchar('\n');
    }
    for (int col = 0; col < 26; ++col) { if (col) putchar(' '); putchar('A' + col); }
    putchar('\n'); return 0;
}
```

[下载完整源码](../solutions/ch05-string-43.c)

## 讲解

1. 统计A到Z各自的出现次数，并找出最大的次数作为柱状图高度。
2. 从最高层往下画：某字母次数不少于当前层号，就在该列画星号，否则画空格。
3. 例如AAB最高2层，第二层只有A列有星，第一层A、B列都有星。
4. 各列用一个空格分开，最后输出A到Z的坐标行。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 样例含空格，应忽略非大写字母。
- 每列仍要占位，不能省去中间的空列。

## 相似题目

- [10.11 字符出现的频率【★】](ch05-string-11.md)：共同练习：字符串、频率统计。
- [10.10 字符出现的次数【★】](ch05-string-10.md)：共同练习：字符串。

## 再练一个用例

检查末列位置与完整坐标轴。。

**输入：**

```text
Z
```

**输出：**

```text
                                                  *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```

---

[上一题：10.42 ISBN号码【★★★】](ch05-string-42.md) · [下一题：10.44 奇怪的A+B【★★★】](ch05-string-44.md)
