#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int sroot(int x) { return static_cast<int>(sqrt(x)); }
long sroot(long x) { return static_cast<long>(sqrt(x)); }
double sroot(double x) { return sqrt(x); }
int main() {
    int i;
    long l;
    double d;
    cin >> i >> l >> d;
    cout << sroot(i) << ',' << sroot(l) << ',' << sroot(d) << '\n';
    return 0;
}
