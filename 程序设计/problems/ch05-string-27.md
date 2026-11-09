# 10.27 回文串【★】

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第27题。

## 题目

10.27 回文串【★】

【题目描述】

回文串是从左到右或者从右到左读起来都一样的字符串，如上海自来水来自海上、青岛多树木树多岛青，以及英文单词madam、level等等。

【输入】

一个长度小于100的字符串。

【输出】

如果是为回文串，则输出“YES”，否则输出“NO”。

例如:

**输入：**

```text
madam
```

**输出：**

```text
YES
```

### 题目与实现说明

- 为覆盖题干提到的中文回文，本解按UTF-8编码拆分完整字符；输入应为有效UTF-8文本。比较区分大小写，空格也参与比较。

## 解答

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s; std::getline(std::cin, s);
    std::vector<std::string> characters;
    for (std::size_t i = 0; i < s.size();) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        std::size_t length = c < 128 ? 1 : (c < 224 ? 2 : (c < 240 ? 3 : 4));
        characters.push_back(s.substr(i, length));
        i += length;
    }
    bool valid = true;
    for (std::size_t i = 0; i < characters.size() / 2; ++i)
        if (characters[i] != characters[characters.size() - 1 - i]) valid = false;
    std::cout << (valid ? "YES\n" : "NO\n");
}
```

[下载完整源码](../solutions/ch05-string-27.cpp)

## 讲解

1. 把输入分成一个个字符；UTF-8的汉字占多个字节，先按首字节确定字符长度。
2. 将第一个与最后一个字符比较，第二个与倒数第二个比较，只检查前一半即可。
3. 例如madam比较m/m、a/a，两对都相同，所以是回文。

## 知识点总结

- std::vector<std::string>：保存拆开的完整字符，既可放英文字母也可放UTF-8汉字。
- substr(i,length)：从字节位置i取出一个完整字符。
- size()-1-i：得到与下标i左右对称的位置。
- bool：保存是否仍满足回文条件。

## 易错点

- 有任意一对不同就不是回文。
- 中文不能简单逐字节反转，UTF-8一个汉字通常占3个字节。

## 相似题目

- [6006 神奇的魔镜](quiz4-05.md)：共同练习：字符串、回文。
- [10.40 镜像文字【★】](ch05-string-40.md)：共同练习：字符串、回文。

## 再练一个用例

检查首尾相同但内部不对称。。

**输入：**

```text
abca
```

**输出：**

```text
NO
```

---

[上一题：10.26 独一无二的字符串【★★】](ch05-string-26.md) · [下一题：10.28 字符串重排列【★★】](ch05-string-28.md)
