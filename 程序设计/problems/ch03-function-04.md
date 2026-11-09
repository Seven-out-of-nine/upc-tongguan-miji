# 【函数】F7.04 求阶乘【★】

[学习首页](../README.md) · [本章目录](../chapters/ch03-function/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第3章 part2函数初步.html，第4题。

## 题目

【函数】F7.04 求阶乘【★】

【题目描述】

请编写求阶乘的函数Facto，其功能是：对录入的任意正整数n进行计算并输出从1到n之间所有数的阶乘值。如果n&gt;0，则输出1~n的阶乘值；否则，提示输入数据错误

【输入】

正整数n。

【输出】

如果n&gt;0，则输出1-n的阶乘值；否则，提示输入数据错误。

预设代码

前置代码

```text
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
```

后置代码

```text
int main()
{
	int n,i;
	double result = 1;
	scanf("%d",&n);
	if(n<=0)
	{
	    printf("Input data error!\n");
	}
	else
	{
	    for(i = 1;i <= n; i++)
	    {
	        result = Facto(i);
	        printf("%d!=%.0f\n",i,result);
	    }
	}
	return 0;
}
```

例如:

**输入：**

```text
3
```

**输出：**

```text
1!=1
2!=2
3!=6
```

### 题目与实现说明

- 原题未给n的上界，原main固定使用double，故本题保留该接口；较大阶乘的精确整数输出需要另设大整数表示。

## 解答

平台已给main，只提交下面函数，勿再提交main。完整程序供本地编译运行。

### 平台提交版

```c
double Facto(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}
```

<details>
<summary>展开完整本地运行程序</summary>

```c
#include <stdio.h>

double Facto(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

int main()
{
	int n,i;
	double result = 1;
	scanf("%d",&n);
	if(n<=0)
	{
	    printf("Input data error!\n");
	}
	else
	{
	    for(i = 1;i <= n; i++)
	    {
	        result = Facto(i);
	        printf("%d!=%.0f\n",i,result);
	    }
	}
	return 0;
}
```

</details>

[下载完整源码](../solutions/ch03-function-04.c)

## 讲解

1. main先检查n是否大于0；不合法时由main输出Input data error!。
2. Facto(i)把result从1开始，依次乘上1至i，得到i!。
3. main循环调用Facto(1)、Facto(2)…Facto(n)，每次打印一行。
4. 例如n=3时，三个返回值分别是1、2、6，输出1!=1、2!=2、3!=6。

## 知识点总结

- double返回类型：原main用double接收阶乘，避免用int在13!就溢出。
- result*=i：等价于result=result*i，把每个因子乘进结果。
- %.0f：把double按小数位数0输出，并不代表变量是整数。

## 易错点

- 累乘的初值必须是1，设成0会让所有结果为0。
- double精度有限；超过约15位的整数未必精确，170!之后还会超出常见double范围。

## 相似题目

- [【函数】F7.05 求级数【★】](ch03-function-05.md)：共同练习：函数。
- [【函数】F7.09 公式求解【★】](ch03-function-09.md)：共同练习：函数。

## 再练一个用例

输入不为正数时不调用阶乘函数。。

**输入：**

```text
0
```

**输出：**

```text
Input data error!
```

---

[上一题：【函数】F7.03 素数的判断【★】](ch03-function-03.md) · [下一题：【函数】F7.05 求级数【★】](ch03-function-05.md)
