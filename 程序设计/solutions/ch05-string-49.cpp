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
