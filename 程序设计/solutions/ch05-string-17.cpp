#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::getline(std::cin, a); std::getline(std::cin, b);
    for (char c : a) if (b.find(c) == std::string::npos) std::cout << c;
    std::cout << '\n';
}
