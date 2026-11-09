#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Rectangle {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getArea() const { return length * width; }
};
int main() {
    double length, width;
    cin >> length >> width;
    Rectangle r(length,width);
    cout << "length is " << r.getLength() << ", width is " << r.getWidth()
         << ", area is " << r.getArea() << '\n';
    return 0;
}
