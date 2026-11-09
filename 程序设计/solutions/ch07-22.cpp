#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Employee {
protected:
    string name;
    int ID;
public:
    Employee(string n,int id) : name(n),ID(id) {}
    void show() const { cout << name << ',' << ID << '\n'; }
};
class Manager : public Employee {
private:
    double sal;
public:
    Manager(string n,int id,double s) : Employee(n,id),sal(s) {}
    void show() const { Employee::show(); cout << sal << '\n'; }
};
class HourlyWorker : public Employee {
private:
    double wage;
    int hours;
public:
    HourlyWorker(string n,int id,double w,int h) : Employee(n,id),wage(w),hours(h) {}
    void show() const { Employee::show(); cout << wage << ',' << hours << '\n'; }
};
int main() {
    Manager mg("Tom",100,6000.0);
    HourlyWorker hw("Mike",1001,20.0,8);
    mg.show(); hw.show();
    return 0;
}
