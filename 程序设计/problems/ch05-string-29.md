# 10.29 城市名排序【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第29题。

## 题目

10.29 城市名排序【★★】

【题目描述】

山东，因居太行山以东而得名，简称“鲁”，省会济南。山东省有2个副省级市（济南、青岛）、15个地级市。从键盘输入n个城市名，按照城市名称的字典顺序进行排序并输出。

【输入】

第一行一个整数n，表示有n个城市。接着有n行，每行一个字符串，每个字符串代表一个城市名，一个字符串内部不包含空格，字符串长度不超过30。

【输出】

排序后的城市名字。每个城市名占据一行。

例如:

**输入：**

```text
10
qingdao
jinan
yantai
weifang
binzhou
dongying
zibo
dezhou
heze
weihai
```

**输出：**

```text
binzhou
dezhou
dongying
heze
jinan
qingdao
weifang
weihai
yantai
zibo
```

## 解答

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    int n; std::cin >> n;
    std::vector<std::string> cities(n);
    for (int i = 0; i < n; ++i) std::cin >> cities[i];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (cities[j] > cities[j + 1]) std::swap(cities[j], cities[j + 1]);
    for (const std::string &name : cities) std::cout << name << '\n';
}
```

[下载完整源码](../solutions/ch05-string-29.cpp)

## 讲解

1. 读取n个城市名，依次存入字符串数组。
2. 相邻两城名字典序反了就交换，每轮把当前最大的名字移到末尾。
3. 例如zibo、jinan、qingdao第一轮把zibo移到末尾，最后得到jinan、qingdao、zibo。

## 知识点总结

- vector<string>(n)：按实际n分配字符串数量，题干未给n上限。
- string的>：比较字符串字典序。
- std::swap：交换两个完整城市名。
- n-1-i：已经排好的末尾不必再比较。

## 易错点

- 按名称字符顺序排序，不按长度排序。

## 相似题目

- [10.24 字符串比较大小【★】](ch05-string-24.md)：共同练习：字符串、字典序。
- [10.22 字符接龙【★】](ch05-string-22.md)：共同练习：字符串。

## 再练一个用例

检查重复城市仍保留。。

**输入：**

```text
3
zibo
beijing
beijing
```

**输出：**

```text
beijing
beijing
zibo
```

---

[上一题：10.28 字符串重排列【★★】](ch05-string-28.md) · [下一题：10.30 字符第一次出现的位置【★】](ch05-string-30.md)
