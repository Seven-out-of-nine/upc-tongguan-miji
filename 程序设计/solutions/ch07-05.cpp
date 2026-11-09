#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int *fib = new int[20];
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 20; i++) fib[i] = fib[i-1] + fib[i-2];
    for (int i = 0; i < 20; i++) {
        cout << setw(10) << fib[i];
        if ((i + 1) % 5 == 0) cout << '\n';
    }
    delete[] fib;
    return 0;
}
