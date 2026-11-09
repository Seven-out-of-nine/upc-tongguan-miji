#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Stock {
private:
    char stockcode[20];
    int quan;
    double price;
public:
    Stock(const char na[], int q = 1000, double p = 8.98) : quan(q), price(p) {
        strcpy(stockcode, na);
    }
    void print() const {
        cout << this->stockcode << '\n' << this->quan << '\n' << this->price << '\n';
    }
};
int main() {
    Stock st1("600001", 3000, 5.67);
    st1.print();
    Stock st2("600002");
    st2.print();
    return 0;
}
