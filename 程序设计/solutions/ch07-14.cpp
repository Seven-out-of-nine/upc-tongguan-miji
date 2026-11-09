#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Student {
private:
    int id, score;
    string name;
    static int count;
    static int total;
public:
    Student(int i, string n, int s) : id(i), score(s), name(n) { count++; total += score; }
    void print() const { cout << id << "   " << name << "   " << score << '\n'; }
    static int getCount() { return count; }
    static double getAverage() { return count ? static_cast<double>(total) / count : 0; }
};
int Student::count = 0;
int Student::total = 0;
int main() {
    Student s1(201601,"john",85), s2(201602,"mike",90), s3(201603,"june",95);
    s1.print(); s2.print(); s3.print();
    cout << "共有" << Student::getCount() << "位学生，平均成绩为：" << Student::getAverage() << '\n';
    return 0;
}
