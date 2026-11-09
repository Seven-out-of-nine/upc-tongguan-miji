#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class building {
protected:
    string name;
    int floors, areas;
public:
    building(string n, int f, int a) : name(n), floors(f), areas(a) {}
    void print() const {
        cout << "建筑物名称：" << name << ", 层数：" << floors << ", 总面积：" << areas << "平方米";
    }
};
class house : public building {
private:
    int bedrooms, bathroom;
public:
    house(string n,int f,int a,int b,int bath) : building(n,f,a),bedrooms(b),bathroom(bath) {}
    void print() const {
        building::print();
        cout << ", 卧室数：" << bedrooms << ", 浴室数：" << bathroom << ".\n";
    }
};
class office : public building {
private:
    int offices, meetingrooms;
public:
    office(string n,int f,int a,int o,int m) : building(n,f,a),offices(o),meetingrooms(m) {}
    void print() const {
        building::print();
        cout << ", 办公室数：" << offices << ", 会议室数：" << meetingrooms << ".\n";
    }
};
int main() {
    house myhouse("江山瑞城",3,200,5,2);
    office myoffice("工科楼E",20,10000,2000,100);
    myhouse.print(); myoffice.print();
    return 0;
}
