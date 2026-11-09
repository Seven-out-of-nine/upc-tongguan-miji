# TJ8.08 The Himalayas【★★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第47题。

## 题目

TJ8.08 The Himalayas【★★★】

As an artist, Bob usually need to travel around the world. He made a lot of sketch of scenery on his journey. A famous spot he have visited recently is the Himalayas. The Himalayas is a mountain range in South Asia separating the plains of the Indian subcontinent from the Qinghai-Tibet Plateau. The Himalayas include over a hundred mountains exceeding 7,200 meters in elevation.

One day, Bob came up with an strange idea. He wanted to know the number of mountain peaks in his paintings. As his best friend, he turned to you for help. You are given a list of N height sampling values H<sub>i</sub>. You should determine how many peaks are there. For all i which satisfies 2 &lt;= i &lt;= N - 1, H<sub>i</sub> is defined as a peak if and only if H<sub>i-1</sub> &lt; H<sub>i</sub> &gt; H<sub>i+1</sub>.

Input

There are multiple test cases. The first line of input contains an integer T indicating the number of test cases. For each test case:

The first line contains one integer N (1 &lt;= N &lt;= 50). The next line contains N integers H<sub>i</sub> (1 &lt;= H<sub>i</sub> &lt;= 8844). It is guaranteed that any two adjacent height sampling values will be different.

Output

For each test case, output the number of peaks.

例如:

**输入：**

```text
2
9
1 3 2 4 6 3 2 3 1
5
1 2 3 4 5
```

**输出：**

```text
3
0
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n, height[50], peaks = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &height[i]);
        for (int i = 1; i + 1 < n; ++i)
            if (height[i] > height[i - 1] && height[i] > height[i + 1]) ++peaks;
        printf("%d\n", peaks);
    }
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-47.c)

## 讲解

1. 题目把峰顶定义为同时高于左邻和右邻的内部采样点。
2. 先读入当前组的高度数组，再只扫描下标1到n-2，检查两个严格大于条件。
3. 两个条件都成立就把peaks加1；每组结束输出本组计数。
4. 例如1、3、2中，3大于两侧1和2，是一个峰；一直递增的1、2、3、4没有内部峰。

## 知识点总结

本题没有新增知识点，沿用前文写法，重点见上面的解题讲解。

## 易错点

- 首项和末项没有两个邻居，都不能作为峰顶。
- n为1或2时扫描循环一次也不执行，答案自然为0。

## 相似题目

- [8.01 小明摘苹果【★】](ch05-array-01.md)：共同练习：数组、计数。
- [8.10 买股票【★★】](ch05-array-10.md)：共同练习：数组。

## 再练一个用例

最小两种规模无峰，三项中间最高才出现峰。。

**输入：**

```text
3
1
5
2
1 2
3
1 3 2
```

**输出：**

```text
0
0
1
```

---

[上一题：TJ8.07 数制转换【★★★★★】](ch05-array-46.md)
