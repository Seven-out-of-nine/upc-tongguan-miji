# 10.36 字符串匹配【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第36题。

## 题目

【题目描述】

字符串匹配是计算机科学中最古老、研究最广泛的问题之一。它的应用包括生物信息学、信息检索、拼写检查、语言翻译、数据压缩、网络入侵检测。输入一个主串str和一个要查早的子串substr，输出子串substr在主串str中首次出现的位置。例如主串str为：ababcabababab,子串为ababa，则子串在主串中首次出现的位置为5。

尝试不用现成的函数实现上述算法。

【输入】

有两行。第1行为主串str，第2行为要查找的子串substr。主串长度不超过100，子串长度小于等于主串长度。

【输出】

子串substr在主串str中首次出现的位置，如果没有出现，输出-1。

例如:

**输入：**

```text
ababcabababab
ababa
```

**输出：**

```text
5
```

### 题目与实现说明

- 样例主串中ababa的第一次起点下标为5（从1数为6），故按0起始下标输出。

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
    char s[103], sub[103]; read_line(s, sizeof s); read_line(sub, sizeof sub);
    int n = 0, m = 0, answer = -1;
    while (s[n]) ++n;
    while (sub[m]) ++m;
    for (int start = 0; start + m <= n; ++start) {
        int j = 0;
        while (j < m && s[start + j] == sub[j]) ++j;
        if (j == m) { answer = start; break; }
    }
    printf("%d\n", answer); return 0;
}
```

[下载完整源码](../solutions/ch05-string-36.c)

## 讲解

1. 计算主串和子串长度，依次试每个放得下子串的起点。
2. 在一个起点逐字符比较，子串全部字符一致就找到匹配，立即停止。
3. 样例在下标5开始匹配ababa，输出5，因此本题位置使用0起始下标。

## 知识点总结

- start+m<=n：保证整个待比较区间都在主串内。
- s[start+j]与sub[j]：比较两串对应字符。
- answer=-1：没有任何完整匹配时保持-1。

## 易错点

- 此题样例要求0起始下标，与10.30和10.31的1起始位置不同。
- 找到部分相同不够，必须j等于完整子串长度。

## 相似题目

- [10.35 GLB串【★★】](ch05-string-35.md)：共同练习：字符串、子串查找。
- [10.30 字符第一次出现的位置【★】](ch05-string-30.md)：共同练习：字符串。

## 再练一个用例

检查开头匹配位置为0。。

**输入：**

```text
ababa
aba
```

**输出：**

```text
0
```

---

[上一题：10.35 GLB串【★★】](ch05-string-35.md) · [下一题：10.37 营业额【★★★】](ch05-string-37.md)
