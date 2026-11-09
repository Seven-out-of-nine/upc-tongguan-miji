#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getCircumference() const { return 2 * 3.14 * radius; }
    double getArea() const { return 3.14 * radius * radius; }
};
int main() {
    double radius;
    cin >> radius;
    Circle c(radius);
    cout << "radius is " << radius << ",perimeter is " << c.getCircumference()
         << ",area is " << c.getArea() << '\n';
    return 0;
}
