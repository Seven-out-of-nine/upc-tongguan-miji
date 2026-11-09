#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Container
{
protected:
    int r;
public:
    Container(int r):r(r){}
   virtual ~Container() = default;
   virtual double surface_area()
    {
       return 0.0;
    }
    virtual double volume()
    {
        return 0.0;
    }
};
class Sphere : public Container
{
public :
    Sphere(int r):Container(r){}
    double surface_area()
    {
        return 3.14*4*r*r;
    }
    double volume()
    {
        return 4.0/3.0*3.14*r*r*r;
    }
};
class Cylinder : public Container
{
private:
    int l;
public :
   Cylinder(int r,int l):Container(r)
   {
       this->l=l;
   }
    double surface_area()
    {
        return 2*3.14*r*r+2*3.14*r*l;
    }
    double volume()
    {
        return 3.14*r*r*l;}
};
class Cube : public Container
{

public :
 Cube (int r):Container(r){}
    double surface_area()
    {
        return 6*r*r;
    }
    double volume()
    {
        return r*r*r;
    }
};
int main()
{
	Container *p;
	Sphere s(5);
	Cylinder c(5,6);
	Cube cu(5);
	p=&s;
	cout<<"The Surface area of the Sphere is "<<p->surface_area()<<endl;
	cout<<"The Volume of the Sphere is "<<p->volume()<<endl;
	p=&c;
	cout<<"The Surface area of the Cylinder is "<<p->surface_area()<<endl;
	cout<<"The Volume of the Cylinder is "<<p->volume()<<endl;
	p=&cu;
	cout<<"The Surface area of the Cube is "<<p->surface_area()<<endl;
	cout<<"The Volume of the Cube is "<<p->volume()<<endl;
	return 0;
}
