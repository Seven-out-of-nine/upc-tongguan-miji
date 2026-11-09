# TJ10.02 A==B？★★

[学习首页](../README.md) · [本章目录](../chapters/ch05-string/README.md) · [知识点索引](../知识点索引.md)

来源：【测验】第5章 part2字符串.html，第46题。

## 题目

TJ10.02 A==B？★★

【题目描述】

给你两个正实数A 、B，判断他们是否相等，如果相等，输出“YES” ，否则输出“NO”。

【输入】

输入数据有多组，每组包括两个正实数 (可能很大,float,double类型变量都无法存储)。

【输出】

如果A与B相等，输出“YES” ，否则输出“NO” 。

例如:

**输入：**

```text
1.0 1.01
1.0 1.0
```

**输出：**

```text
NO
YES
```

### 题目与实现说明

- 按题目常见的十进制非负表示处理，可有小数点；未定义的科学计数法不在本解输入约定内。

## 解答

```cpp
#include <iostream>
#include <string>

std::string normalize(std::string s) {
    std::size_t dot = s.find('.');
    if (dot == std::string::npos) dot = s.size();
    std::string integer = s.substr(0, dot);
    std::size_t first = integer.find_first_not_of('0');
    integer = first == std::string::npos ? "0" : integer.substr(first);
    std::string fraction = dot < s.size() ? s.substr(dot + 1) : "";
    while (!fraction.empty() && fraction.back() == '0') fraction.pop_back();
    return fraction.empty() ? integer : integer + "." + fraction;
}
int main() {
    std::string a, b;
    while (std::cin >> a >> b) std::cout << (normalize(a) == normalize(b) ? "YES\n" : "NO\n");
}
```

[下载完整源码](../solutions/ch05-string-46.cpp)

## 讲解

1. 把实数当字符串读取，避免浮点数容量和精度限制。
2. 整数部分删除前导0，但至少保留一个0；小数部分删除末尾0。
3. 小数部分为空就不保留小数点，形成统一表示。
4. 例如0001.2300与1.23规范化后都是1.23，因此相等。

## 知识点总结

- std::string：能保存远超double范围的十进制数字。
- find('.')：定位小数点，无小数点时返回npos。
- back()/pop_back()：查看并删除末尾字符，使用前先判非空。
- normalize：把不同写法转换为唯一可比较的写法。

## 易错点

- 只能删整数前导零和小数末尾零，不能删除中间或小数开头有意义的零。
- 不能用double或误差比较处理题目中的超大实数。

## 相似题目

- [10.37 营业额【★★★】](ch05-string-37.md)：共同练习：字符串、大整数。
- [10.24 字符串比较大小【★】](ch05-string-24.md)：共同练习：字符串。

## 再练一个用例

检查等值不同写法和小数内部零。。

**输入：**

```text
0001.2300 1.23
1.01 1.001
```

**输出：**

```text
YES
NO
```

---

[上一题：10.45 库函数技巧【★】](ch05-string-45.md) · [下一题：TJ10.07 字符串王国的种族★★](ch05-string-47.md)
