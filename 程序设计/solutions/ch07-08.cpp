#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Rectangle {
private:
    int x1, y1, x2, y2;
public:
    Rectangle(int a, int b, int c, int d) { setPoints(a,b,c,d); }
    void setPoints(int a, int b, int c, int d) { x1=a; y1=b; x2=c; y2=d; }
    int getX1() const { return x1; }
    int getY1() const { return y1; }
    int getX2() const { return x2; }
    int getY2() const { return y2; }
    long long getArea() const { return 1LL * (x2-x1) * (y1-y2); }
};
int main() {
    Rectangle rect(100,80,200,40);
    cout << "Area: " << rect.getArea() << '\n';
    return 0;
}
