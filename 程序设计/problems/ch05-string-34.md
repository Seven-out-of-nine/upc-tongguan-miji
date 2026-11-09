# 10.34 小明去过的城市【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第34题。

## 题目

【题目描述】

小明喜欢旅游，每次都会去一个地方，并且每去过一个地方都会记录一下地名，当然有些地方去过多次也都会一一记录下来的。现在列出了小明去过的n个城市的名称（会有重复的），然后再输入一个城市的名称，想请你帮忙计算一下这个城市小明去过几次了。

【输入】

有多行。第1行一个正整数n（n小于等于100），表示小明在旅行中去过n个地方了。接下来n行依次输入n个字符串表示城市名，每个字符串的长度小于等于40字符，并且字符串中无空格，可能会有重复的城市名。最后再输入一个城市名表示待查找字符串。

【输出】

该城市小明已经去过几次了。

例如:

**输入：**

```text
4
shanghai
beijing
hangzhou
beijing
beijing
```

**输出：**

```text
2
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int n; char cities[100][41], target[41]; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%40s", cities[i]);
    scanf("%40s", target);
    int count = 0;
    for (int i = 0; i < n; ++i) if (strcmp(cities[i], target) == 0) ++count;
    printf("%d\n", count); return 0;
}
```

[下载完整源码](../solutions/ch05-string-34.c)

## 讲解

1. 先读n条旅行记录，重复记录也保留。
2. 读入待查询城市，逐条与它比较，相等就累加次数。
3. 例如beijing、xian、beijing查询beijing，累加两次得到2。

## 知识点总结

- cities[100][41]：最多100个城市，每个留1格结束符。
- strcmp返回0：代表城市名相同。
- ++count：每一条匹配的旅行记录都计算一次。

## 易错点

- 不能先去重，否则会丢掉访问次数。

## 相似题目

- [10.25 相同的字符串【★★★】](ch05-string-25.md)：共同练习：字符串、频率统计。
- [10.33 上课点名 【★★】](ch05-string-33.md)：共同练习：字符串、查找。

## 再练一个用例

检查从未访问的城市。。

**输入：**

```text
2
a
b
c
```

**输出：**

```text
0
```

---

[上一题：10.33 上课点名 【★★】](ch05-string-33.md) · [下一题：10.35 GLB串【★★】](ch05-string-35.md)
