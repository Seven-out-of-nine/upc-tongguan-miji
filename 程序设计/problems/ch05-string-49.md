# TJ10.11 反序输出英文单词★

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第49题。

## 题目

TJ10.11 反序输出英文单词★

【题目描述】

以规范的格式反序输出一句英文的单词，句子前后无多余空格，每个单词之前以一个空格分隔。

注意原文可能是不规整的，单词间、整个句子前后都多了多余空格。例如：

输入： I am student

输出：student am I

【输入】

一行英文，不超过100个单词。

【输出】

反序后的结果。

例如:

**输入：**

```text
I am student
```

**输出：**

```text
student am I
```

## 解答

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line, word;
    std::getline(std::cin, line);
    std::istringstream input(line);
    std::vector<std::string> words;
    while (input >> word) words.push_back(word);
    for (std::size_t i = words.size(); i > 0; --i) {
        if (i != words.size()) std::cout << ' ';
        std::cout << words[i - 1];
    }
    std::cout << '\n';
}
```

[下载完整源码](../solutions/ch05-string-49.cpp)

## 讲解

1. 先整行读取，再用字符串输入流按单词分割，自动跳过连续空白。
2. 把所有词按原顺序存起来，再从最后一个词向前输出。
3. 例如多余空格包围的I am student仍分成三个词，输出student am I。
4. 只在相邻输出词之间放一个空格，避免句首句尾多余空格。

## 知识点总结

- **istringstream按词解析文本**：<sstream>中的std::istringstream input(line)把已有字符串当成输入流。while(input >> word)依次提取单词并自动跳过连续空白，不必改变原始输入或自己维护分词起点。

## 易错点

- 只倒转单词顺序，不倒转每个词内部的字母。
- 不能原样保留输入多余空格。

## 相似题目

- [10.12 单词统计【★】](ch05-string-12.md)：共同练习：字符串、单词处理。
- [TJ10.10 首字母大写★★](ch05-string-48.md)：共同练习：字符串、单词处理。

## 再练一个用例

检查首尾与词间多余空格。。

**输入：**

```text
  one   two  three
```

**输出：**

```text
three two one
```

---

[上一题：TJ10.10 首字母大写★★](ch05-string-48.md)
