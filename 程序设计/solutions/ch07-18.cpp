#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class Document {
protected:
    string name; 
public:
    
    Document(string n) : name(n) {}
};


class Book : public Document {
private:
    int pageCount; 
public:
    
    Book(string n, int p) : Document(n), pageCount(p) {}

    
    void printNameOf() {
        cout << "Name of book: " << name << endl;
    }
};

int main()
{
    Document a("Document1");
    Book b("Book1",100);
    b.printNameOf();
    return 0;
}
