#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Tree {
private:
    int ages;
public:
    Tree(int a) : ages(a) {}
    void grow(int years) { ages += years; }
    void age() const { cout << "this tree's age is " << ages << '\n'; }
};
int main() {
    Tree t(12);
    t.age();
    t.grow(4);
    t.age();
    return 0;
}
