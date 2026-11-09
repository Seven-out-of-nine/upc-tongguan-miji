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

- **C++标准命名空间**：std::string、std::cin中的std是标准库命名空间，::指出名字所属的作用域。本解保留std::前缀，让标准库名字与自己定义的名字区分；后续类名::成员也是用作用域限定名字。
- **C++输入输出流**：<iostream>提供std::cin和std::cout：cin >> x按x的类型读取一个值，cout << x输出一个值，操作可以连续连接。>>读取字符串时以空白分词；读取成功可作循环条件。'\n'只写换行；std::endl还会刷新输出缓冲区。
- **std::string管理文本**：<string>中的std::string自动管理文本长度；声明std::string a就可保存一串字符，无须自己预留固定数组及结束符。s[i]仍以0起始下标访问一个字节，s.size()返回字节数，不能把UTF-8汉字字数直接等同于size()。
- **getline读取C++整行文本**：std::getline(std::cin,a)把一整行保存到std::string a，保留行内空格，读走分隔换行但不把它放入a。它不同于cin >> a；如先用>>读数，切换getline前仍需处理残留换行。
- **C++按元素循环**：for (char c : a)依次取字符串a的每个字节，让c保存当前字符，不必自己写下标和上界。这里c是副本，改c不会改变a；若要访问原元素，可以使用后面介绍的引用。
- **string的查找结果与npos**：b.find(c)查找字符c第一次出现的下标，找不到返回std::string::npos；它不是普通的0或-1。只有结果不是npos时才可把它用作位置。find_first_not_of('0')则找到第一个不属于给定字符集合的位置。

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
