# 10.17 删除指定字符串【★★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第17题。

## 题目

10.17 删除指定字符串【★★】

【题目描述】

输入两个字符串s1和s2，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”。

【输入】

两个字符串 s1 和 s2。

【输出】

删除后的字符串 s1。

提示：使用string对象的find\_first\_of、erase方法会大大降低难度。

例如:

**输入：**

```text
They are students.
aeiou
```

**输出：**

```text
Thy r stdnts.
```

## 解答

```cpp
#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::getline(std::cin, a); std::getline(std::cin, b);
    for (char c : a) if (b.find(c) == std::string::npos) std::cout << c;
    std::cout << '\n';
}
```

[下载完整源码](../solutions/ch05-string-17.cpp)

## 讲解

1. 分别整行读取原文a和待删字符集合b。
2. 扫描a中的每个字符，在b中查找；找不到才保留。
3. 例如banana和an表示删除所有a、n，最终只剩b。

## 知识点总结

- std::string：自动管理文本长度，题干未给长度上限也可读取。
- b.find(c)：在b中寻找字符c的位置。
- std::string::npos：表示没有找到，因此该字符应该输出。

## 易错点

- 第二行表示一组要删的字符，不是仅删除完整连续子串。

## 相似题目

- [10.16 删除指定字符【★】](ch05-string-16.md)：共同练习：字符串、字符过滤。
- [10.18 删除重复字符【★★】](ch05-string-18.md)：共同练习：字符串。

## 再练一个用例

检查删除字符集合的含义。。

**输入：**

```text
banana
an
```

**输出：**

```text
b
```

---

[上一题：10.16 删除指定字符【★】](ch05-string-16.md) · [下一题：10.18 删除重复字符【★★】](ch05-string-18.md)
