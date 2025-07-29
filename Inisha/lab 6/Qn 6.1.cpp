#include <iostream>
using namespace std;
class Base {
public:
    // Virtual function
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};
class Derived : public Base {
public:
    // Overriding display function
    void display() override {
        cout << "Display from Derived class" << endl;
    }
};
int main() {
    // Base class pointer pointing to Derived class object
    Base* ptr = new Derived();

    ptr->display();
    delete ptr;
    return 0;
}
