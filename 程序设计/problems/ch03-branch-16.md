# \[5.16\]计算一元二次方程的根★★★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第16题。

## 题目

描述

从键盘上任意输入 a,b,c 的值，编程计算并输出一元二次方程 ax<sup>2</sup>+bx+c=0 的根，当 a=0 时，输出“Not quadratic equation with one unknown!”，当 a≠0 时，分 b<sup>2</sup>-4ac&gt;0 ，b<sup>2</sup>-4ac=0 ，b<sup>2</sup>-4ac&lt;0 三种情况计算并输出方程的根。当 b<sup>2</sup>-4ac&lt;0 时，输出“No real roots”，若有两根，按从小到大顺序输出,结果保留3位小数，若只有一个根，则输出一个即可。

注意：浮点数不能和0比较是否相等，本题 |a| &lt;0.000001时视为0

输入

a,b,c

输出

x1，x2

例如:

**输入：**

```text
1,1,-2
```

**输出：**

```text
-2.000,1.000
```

### 题目与实现说明

- 原题仅对a约定1e-6的零阈值。本解的判别式误差界为4*LDBL_EPSILON*(|b²|+|4ac|)，只处理浮点表示和乘减舍入造成的极小残差，不额外规定1e-12等宽泛的近似重根区间。输入系数及b²、4ac等中间运算需处于long double可表示的有限范围内。

## 解答

```c
#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)
{
    long double a, b, c;
    scanf("%Lf,%Lf,%Lf", &a, &b, &c);
    if (fabsl(a) < 0.000001L) {
        puts("Not quadratic equation with one unknown!");
    } else {
        long double delta = b * b - 4 * a * c;
        long double error_bound = 4 * LDBL_EPSILON * (fabsl(b * b) + fabsl(4 * a * c));
        if (fabsl(delta) <= error_bound) delta = 0;
        if (delta == 0) {
            long double root = -b / (2 * a);
            if (root == 0) root = 0.0;
            printf("%.3Lf\n", root);
        } else if (delta < 0) {
            puts("No real roots");
        } else {
            long double x1 = (-b - sqrtl(delta)) / (2 * a);
            long double x2 = (-b + sqrtl(delta)) / (2 * a);
            if (x1 > x2) {
                long double temp = x1;
                x1 = x2;
                x2 = temp;
            }
            printf("%.3Lf,%.3Lf\n", x1, x2);
        }
    }
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-16.c)

## 讲解

1. 先按题目规定检查a的绝对值是否小于0.000001，若是就不再当作一元二次方程。
2. 计算判别式delta=b*b-4*a*c，并仅把机器舍入误差量级的微小残差归为0；然后按负、零、正分别处理无实根、单根、两根。
3. 例如1,1,-2的delta=9，根为(-1-3)/2=-2与(-1+3)/2=1，输出-2.000,1.000。
4. 当a为负数时，公式中的“减平方根”不一定给较小根，因此计算完要比较并交换。

## 知识点总结

- long double：通常比double提供更多有效数字，减小判别式相减时的精度损失；scanf读取它用%Lf。
- fabsl与sqrtl：<math.h>中适用于long double的绝对值和平方根函数，sqrtl只在判别式非负时使用。
- LDBL_EPSILON：<float.h>给出的机器精度，用它估计乘减运算的舍入误差；不能直接把a的1e-6阈值用于判别式。
- 临时变量交换：temp暂存x1，再将x2放入x1，最后把原x1放入x2。
- %.3Lf：输出long double时保留3位小数，两根中间用英文逗号。

## 易错点

- a=0要最先处理，否则求根公式会除以0。
- 不能不加判断就对负的delta调用sqrt。
- 两个根需要从小到大输出，只有重根时输出一个。

## 相似题目

- [\[3.10\]求三角形面积★★](ch02-13.md)：共同练习：数学函数。
- [\[5.18\]排序三个数大小★★★](ch03-branch-18.md)：可对照练习：排序、交换，比较输入、处理步骤和输出的变化。
- [\[5.28\]绝对值★](ch03-branch-28.md)：共同练习：条件分支。

## 再练一个用例

a为负仍要排序。

**输入：**

```text
-1,1,2
```

**输出：**

```text
-1.000,2.000
```

---

[上一题：\[5.15\]一共跑了几天操★★](ch03-branch-15.md) · [下一题：\[5.17\]比较两个数大小★](ch03-branch-17.md)
