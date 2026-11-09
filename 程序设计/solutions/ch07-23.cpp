#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Time {
private:
    int hour, minute, second;
public:
    Time(int h,int m,int s) : hour(h),minute(m),second(s) {}
    void display() const { cout << hour << "时" << minute << "分" << second << "秒"; }
};
class Date {
private:
    int year, month, day;
public:
    Date(int y,int m,int d) : year(y),month(m),day(d) {}
    void display() const { cout << year << "年" << month << "月" << day << "日"; }
};
class Birthtime : public Time, public Date {
private:
    string Childname;
public:
    Birthtime(int y,int mo,int d,int h,int mi,int s,string n)
        : Time(h,mi,s),Date(y,mo,d),Childname(n) {}
    void display() const {
        cout << "姓名：" << Childname << '\n' << "出生年月：";
        Date::display();
        cout << '\n' << "出生时间：";
        Time::display();
    }
};
int main() {
    Birthtime boy(2000,12,21,10,15,25,"皮皮");
    boy.display();
    return 0;
}
