#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Mammal {
private:
    int age;    
    int weight; 
public:
    
    Mammal(int a, int w) : age(a), weight(w) {
        cout << "Mammal constructor......" << endl;
    }

    
    ~Mammal() {
        cout << "Mammal destructor......" << endl;
    }

    
    void setAge(int a) { age = a; }
    void setWeight(int w) { weight = w; }
    int getAge() const { return age; }
    
    int getWeight() const { return weight; }

    
    void speak() const {
        cout << "Mammal sound!" << endl;
    }
};


class Dog : public Mammal {
private:
    string color; 
public:
    
    Dog(int a, int w, string c) : Mammal(a, w), color(c) {
        cout << "Dog constructor......" << endl;
    }

    
    ~Dog() {
        cout << "Dog destructor......" << endl;
    }

    
    void setColor(string c) { color = c; }
    string getColor() const { return color; }

    
    void wagtail() const {
        cout << "Tail wagging......" << endl;
    }
};

int main()
{
      Dog jack(2,20,"grown");
      jack.speak();
      jack.wagtail();
      cout<<"jack is "<<jack.getAge()<<" years old, "<<jack.getWeight()<<" pounds, "<<jack.getColor()<<"."<<endl;
      return 0;
}
