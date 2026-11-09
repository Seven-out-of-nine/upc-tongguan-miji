# 8.09 Box of Brick【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-array/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part1数组.html，第9题。

## 题目

**【题目描述】**

Little Bob likes playing with his box of bricks. He puts the bricks one upon another and builds stacks of different height. ''Look, I've built a wall!'', he tells his older sister Alice. ''Nah, you should make all stacks the same height. Then you would have a real wall.'', she retorts. After a little consideration, Bob sees that she is right. So he sets out to rearrange the bricks, one by one, such that all stacks are the same height afterwards. But since Bob is lazy he wants to do this with the minimum number of bricks moved. Can you help?（原网页此处引用搬砖示意图，保存文件未包含该图片；完整操作规则见上述文字与样例。）

**【输入】**

The input consists of two lines. The first line contains the number n of stacks Bob has built. The next line contains n numbers, the heights hi of the n stacks. You may assume 1≤n≤50,1≤hi≤100.

The total number of bricks will be divisible by the number of stacks. Thus, it is always possible to rearrange the bricks such that all stacks have the same height.

**【输出】**

Print the line ''The minimum number of moves is k.'', where k is the minimum number of bricks that have to be moved in order to make all the stacks the same height.

例如:

**输入：**

```text
6
5 2 4 1 7 5
```

**输出：**

```text
The minimum number is 5.
```

### 题目与实现说明

- 外部示意图片未保存，但文字已完整给出搬动规则、堆高与可整除条件，足以解题，不依赖猜图。
- 英文输出说明写The minimum number of moves is k.，本地样例和通过答案写The minimum number is k.，本解按样例输出。
- 搬砖示意图是原网页的外部资源，未随文件保存；本题文字已给出将各堆调整到相同高度的完整规则。

## 解答

```c
#include <stdio.h>

int main(void)
{
    int n, height[50], sum = 0, moves = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &height[i]); sum += height[i]; }
    int average = sum / n;
    for (int i = 0; i < n; ++i)
        if (height[i] > average) moves += height[i] - average;
    printf("The minimum number is %d.\n", moves);
    return 0;
}
```

[下载完整源码](../solutions/ch05-array-09.c)

## 讲解

1. 所有砖块数量不变且最后每堆等高，目标高度必然是总高度除以堆数。
2. 比平均高度高的堆必须搬走多余砖块，把所有多余数量加起来就是最少搬动次数。
3. 把多余的砖直接搬到不足的堆，每块只移动一次，说明这个次数确实能达到。
4. 例如样例总高24、6堆，目标4；5、7、5三堆各多1、3、1块，共搬5块。

## 知识点总结

- **总量不变时的均分与最少转移**：各堆总量保持不变且最终等高时，目标必为总量/堆数。高于目标的每一块都至少要移走一次；把这些多余砖直接放到不足的堆又能每块只移一次，所以多余数量之和就是最少操作数，不能再把不足量加一遍。

## 易错点

- 多余量和不足量相等，若将两者都相加会多算一倍。
- 本地样例的输出句子与英文输出说明不同，需要遵循平台实际格式。

## 相似题目

- [8.08 歌手大奖赛【★】](ch05-array-08.md)：共同练习：平均值、累加。
- [8.30 输油管道【★★★】](ch05-array-30.md)：可对照练习：中位数、排序，比较输入、处理步骤和输出的变化。

## 再练一个用例

已等高时不需要搬动。。

**输入：**

```text
3
4 4 4
```

**输出：**

```text
The minimum number is 0.
```

---

[上一题：8.08 歌手大奖赛【★】](ch05-array-08.md) · [下一题：8.10 买股票【★★】](ch05-array-10.md)
