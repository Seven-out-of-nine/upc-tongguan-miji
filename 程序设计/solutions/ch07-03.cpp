#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Rectangle {
private:
    int length, width;
public:
    void setData(int l, int w) { length = l; width = w; }
    long long perimeter() const { return 2LL * (length + (long long)width); }
    long long area() const { return 1LL * length * width; }
};
int main() {
    int l, w;
    char comma;
    cin >> l >> comma >> w;
    Rectangle r;
    r.setData(l, w);
    cout << "perimeter:" << r.perimeter() << ",area:" << r.area() << '\n';
    return 0;
}
