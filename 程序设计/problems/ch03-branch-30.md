# \[5.30\]温度转换★★

[学习首页](../README.md) · [本章目录](../chapters/ch03-branch/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part1分支.html，第30题。

## 题目

【题目描述】

经常出国旅行的驴友都知道，需要及时了解当地的气温状况。但不少国家采用了不同的温度计量单位：有些使用华氏温度标准（F），有些使用摄氏温度（C）。现在，请你根据温度转换公式设计一个温度转换程序，可以进行温度转换。如果输入摄氏温度，显示转换的华氏温度；如果输入华氏温度，显示转换的摄氏温度。温度转换的公式为：F=(C×9/5)+32 ，式中F表示华氏温度，C表示摄氏温度。

【输入】

仅一行，2个数。第一个为整数（1或2）表示转换的类型，1表示华氏温度转换为摄氏温度，2表示摄氏温度转华氏温度；第2个为浮点数表示需要转换的温度值。

【输出】

转换后的温度值（保留小数点后 2 位）。输出格式为“The Centigrade is 37.78”或“The Fahrenheit is 37.78”。

例如:

**输入：**

```text
1 100
```

**输出：**

```text
The Centigrade is 37.78
```

## 解答

```c
#include <stdio.h>

int main(void)
{
    int type;
    double temperature;
    scanf("%d %lf", &type, &temperature);
    if (type == 1) {
        double centigrade = (temperature - 32) * 5.0 / 9.0;
        printf("The Centigrade is %.2f\n", centigrade);
    } else {
        double fahrenheit = temperature * 9.0 / 5.0 + 32;
        printf("The Fahrenheit is %.2f\n", fahrenheit);
    }
    return 0;
}
```

[下载完整源码](../solutions/ch03-branch-30.c)

## 讲解

1. 先读取转换类型，1表示华氏转摄氏，2表示摄氏转华氏。
2. 类型1使用C=(F-32)*5/9，类型2使用F=C*9/5+32。
3. 例如1 100算得(100-32)*5/9约37.7778，按两位小数输出The Centigrade is 37.78。

## 知识点总结

- int与double：type保存固定编号，temperature保存可能带小数的温度。
- 5.0/9.0：明确进行实数运算，避免把比例先算成整数0。
- 格式化字符串：两种方向分别使用Centigrade和Fahrenheit，大小写按题目要求。

## 易错点

- 方向1和方向2不能交换。
- 若写成temperature*(9/5)，括号中的整数除法先得到1，会导致摄氏转华氏错误。

## 相似题目

- [\[4.09\]战斗机加速度★★](ch02-22.md)：共同练习：单位换算、实数运算。
- [\[4.06\]冰箱的温度★](ch02-19.md)：共同练习：实数运算。
- [\[4.08\]旅行时间和花费★](ch02-21.md)：共同练习：实数运算。

## 再练一个用例

摄氏冰点转华氏。

**输入：**

```text
2 0
```

**输出：**

```text
The Fahrenheit is 32.00
```

---

[上一题：\[5.29\]奇偶数★](ch03-branch-29.md) · [下一题：\[5.31\]出租车计费★★](ch03-branch-31.md)
