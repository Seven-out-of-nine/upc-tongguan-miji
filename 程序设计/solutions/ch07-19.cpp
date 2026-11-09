#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define PI 3.14159
class Shape {
public:
    virtual ~Shape() = default;
    virtual void getArea() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void getArea() override {
        double area = PI * radius * radius;
        
        cout << fixed << setprecision(1) << "The area of the Circle is " << area << endl;
        
        cout.unsetf(ios::fixed);
        cout.precision(6);
    }
};

class Rectangle : public Shape {
protected:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void getArea() override {
        double area = width * height;
        cout << "The area of the Rectangle is " << area << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void getArea() override {
        double area = width * height;
        cout << "The area of the Square is " << area << endl;
    }
};

int main()
{
    Circle c(5);
    c.getArea();
    Rectangle r(4,6);
    r.getArea();
    Square s(5);
    s.getArea();
    return 0;
}
