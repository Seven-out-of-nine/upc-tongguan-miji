#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Point {
private:
    double x; 
    double y; 
public:
    
    Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

    
    double getX() { return x; }
    
    double getY() { return y; }
};


class Line {
private:
    Point start; 
    Point end;   
public:
    
    Line(Point s, Point e) : start(s), end(e) {}

    
    double getLen() {
        double dx = end.getX() - start.getX();
        double dy = end.getY() - start.getY();
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
	Point p1(1,1),p2(4,5);
	Line line1(p1,p2);
	Line line2(line1);
	cout<<"The length of the line1 is:"<<line1.getLen()<<endl;
	cout<<"The length of the line2 is:"<<line2.getLen()<<endl;
	return 0;
}
