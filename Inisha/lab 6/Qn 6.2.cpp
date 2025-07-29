#include <iostream>
using namespace std;
class Shape {
public:
    virtual ~Shape() {
        cout << "Shape destructor called" << endl;
    }
};
class Circle : public Shape {
public:
    // Constructor
    Circle() {
        cout << "Circle constructor called" << endl;
    }
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};
int main() {
    // Shape pointer pointing to a Circle object
    Shape* s = new Circle();
    delete s;
    return 0;
}

