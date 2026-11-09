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
