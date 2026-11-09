#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Calculator {
public:
    int add(int a, int b) const { return a + b; }
    int sub(int a, int b) const { return a - b; }
    int mul(int a, int b) const { return a * b; }
    int div(int a, int b) const { return a / b; }
};
int main() {
    Calculator calc;
    int a, b, answer;
    char op;
    while (cin >> a >> op >> b) {
        if (op == '+') answer = calc.add(a, b);
        else if (op == '-') answer = calc.sub(a, b);
        else if (op == '*') answer = calc.mul(a, b);
        else if (op == '/' && b != 0) answer = calc.div(a, b);
        else continue;
        cout << a << op << b << '=' << answer << '\n';
    }
    return 0;
}
