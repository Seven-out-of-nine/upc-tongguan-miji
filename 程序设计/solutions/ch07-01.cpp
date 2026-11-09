#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    void setDate(int y, int m, int d) {
        year = y; month = m; day = d;
    }
    void showDate() const {
        cout << year << '-' << month << '-' << day << '\n';
    }
};
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    Date date;
    date.setDate(y, m, d);
    date.showDate();
    return 0;
}
