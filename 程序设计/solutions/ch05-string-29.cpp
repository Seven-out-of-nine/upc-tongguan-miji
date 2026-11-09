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
