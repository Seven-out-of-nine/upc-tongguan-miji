#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Dog {
private:
    int age, weight;
public:
    Dog(int a, int w) : age(a), weight(w) {}
    int getAge() const { return age; }
    int getWeight() const { return weight; }
    void setAge(int a) { age = a; }
    void setWeight(int w) { weight = w; }
};
int main() {
    Dog Jack(2, 10);
    cout << "Jack is a Dog who is " << Jack.getAge() << " years old and "
         << Jack.getWeight() << " pounds weight\n";
    Jack.setAge(7);
    Jack.setWeight(20);
    cout << "Now Jack is " << Jack.getAge() << " years old and "
         << Jack.getWeight() << " pounds weight.\n";
    return 0;
}
