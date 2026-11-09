# 20208 夏边看奥运会比赛

[学习首页](../README.md) · [本章目录](../chapters/quiz6/README.md) · [知识点索引](../知识点索引.md)

来源：随堂测验6.html，第6题。

## 题目

20208 夏边看奥运会比赛

【题目描述】

夏边很爱看奥运会直播，在决赛过程中他会忘我的喊加油，在中国选手夺冠的一刹那，他会情不自禁的大喊，为中国骄傲、自豪！众多比赛中，夏边最爱看举重比赛，甚至不用解说员和字幕的帮助，他单凭杠铃片的颜色就能快速算出选手挑战的重量是多少。总重量是由杠铃杆重量+杠铃片重量组成的，空杆的重量固定是18kg，杠铃片的重量是可以通过颜色区分的：red（25kg）、blue（20kg）、yellow（15kg）、green（10kg）、brown（5kg）。因为比赛时杠铃两侧的杠铃片完全对称，所以夏边只需要数一下单侧有哪些颜色的杠铃片就可以啦~~~例如，单侧只有一个红色的杠铃片，那么总重量就是68kg。现在，夏边要给所有出场选手算重量啦。

【输入】

输入数据有N组(1&lt;=N&lt;=100)，代表各选手成绩，输入-1表示结束；每组第一个数表示单侧杠铃片数量，然后是每个杠铃片的颜色，以空格分隔。

【输出】

对每组数据依次输出该选手挑战的重量（单位kg），并且在最后一行输出最大值（参考输出格式）。

例如:

**输入：**

```text
1 red
3 red red brown
-1
```

**输出：**

```text
68
128
max=128
```

## 解答

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int n, maximum = 0;
    while (scanf("%d", &n) == 1 && n != -1) {
        int total = 18;
        for (int i = 0; i < n; ++i) {
            char color[16]; scanf("%15s", color);
            int weight = 0;
            if (strcmp(color,"red") == 0) weight = 25;
            else if (strcmp(color,"blue") == 0) weight = 20;
            else if (strcmp(color,"yellow") == 0) weight = 15;
            else if (strcmp(color,"green") == 0) weight = 10;
            else if (strcmp(color,"brown") == 0) weight = 5;
            total += 2 * weight;
        }
        printf("%d\n", total);
        if (total > maximum) maximum = total;
    }
    printf("max=%d\n", maximum); return 0;
}
```

[下载完整源码](../solutions/quiz6-06.c)

## 讲解

1. 每组从固定18千克的杠铃杆开始累计。
2. 读取单侧各片颜色，查出单片重量，乘2后加上，因为左右完全对称。
3. 例如一侧red和brown是25+5千克，总重量18+2×30=78千克。
4. 每组输出一次，并更新最大值；遇到-1后输出max=最大值。

## 知识点总结

- strcmp：比较颜色名内容，而不是比较字符数组地址。
- total+=2*weight：把两侧同色片一起加入总重量。
- maximum：保存此前所有选手的最大总重量。
- n!=-1：-1是终止标志，不能当成片数处理。

## 易错点

- 不能漏掉杠铃杆18千克。
- 输入是单侧片数，片重一定要乘2。

## 相似题目

- [10.44 奇怪的A+B【★★★】](ch05-string-44.md)：共同练习：字符串。
- [20106 胡恼的差旅统计](quiz5-05.md)：共同练习：最值。

## 再练一个用例

检查双侧重量以及前面组为最大。。

**输入：**

```text
2 red brown
1 blue
-1
```

**输出：**

```text
78
58
max=78
```

---

[上一题：20206 夏边是逃课小王子](quiz6-05.md)
