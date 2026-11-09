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
    double circumference() const { return 2 * 3.14 * radius; }
    double area() const { return 3.14 * radius * radius; }
};
int main() {
    double radius;
    cout << "Enter the radius of the pool:\n";
    cin >> radius;
    Circle pool(radius), rim(radius+3);
    cout << "Fencing Cost is $" << rim.circumference()*35 << '\n';
    cout << "Concrete Cost is $" << (rim.area()-pool.area())*20 << '\n';
    return 0;
}
