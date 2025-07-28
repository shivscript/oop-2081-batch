#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int year;
    string brand;
    string model;

public:
    void set() {
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
    }

    void get() {
        cout << "Details: " << endl;
        cout << "Brand    " << "Model    " << "Year" << endl;
        cout << brand << "    " << model << "    " << year;
    }
};

int main() {
    Car c;
    c.set();
    c.get();
    return 0;
}
