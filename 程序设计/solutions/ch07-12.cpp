#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class cylinder {
private:
    double radius, height, volume;
public:
    cylinder(double r, double h) : radius(r), height(h) {
        volume = 3.141592 * radius * radius * height;
    }
    void vol() const { cout << "volume is:  " << volume; }
};
int main() {
    double r, h;
    cin >> r >> h;
    cylinder x(r,h);
    x.vol();
    return 0;
}
