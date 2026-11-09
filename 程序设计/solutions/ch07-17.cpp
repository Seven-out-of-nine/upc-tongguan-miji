#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class complex {
private:
    double real;  
    double imag;  
public:
    
    complex(double r = 0, double i = 0) : real(r), imag(i) {}

    
    complex add(complex& c) {
        return complex(real + c.real, imag + c.imag);
    }

    
    complex sub(complex& c) {
        return complex(real - c.real, imag - c.imag);
    }

    
    complex mul(complex& c) {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return complex(r, i);
    }

    
    complex div(complex& c) {
        double denominator = c.real * c.real + c.imag * c.imag; 
        double r = (real * c.real + imag * c.imag) / denominator;
        double i = (imag * c.real - real * c.imag) / denominator;
        return complex(r, i);
    }

    
    void print() {
        cout << real << (imag >= 0 ? "+" : "-") << abs(imag) << "i" << endl;
    }
};

int main()
{
	complex c1(2.3,4.6),c2(3.6,2.8),c3,c4,c5,c6;
	c3=c1.add(c2);
	c3.print();
	c4=c1.sub(c2);
	c4.print();
	c5=c1.mul(c2);
	c5.print();
	c6=c1.div(c2);
	c6.print();
	return 0;
}
