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
