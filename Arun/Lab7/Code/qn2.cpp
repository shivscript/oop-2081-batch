/*Create a base class Shape with a virtual destructor.  Create a derived class Circle that has a 
constructor and destructor. Implement a main() function to demonstrate the use of virtual destructors
 by creating a Shape pointer pointing to a Circle object.*/
#include <iostream>
using namespace std;
class Shape {
public:
    Shape() {
        cout << "Shape constructor called" << endl;
    }
    virtual ~Shape() {
        cout << "Shape destructor called" << endl;
    }
};

class Circle : public Shape {
public:
    Circle() {
        cout << "Circle constructor called" << endl;
    }
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};
int main() {
    Shape* shapePtr = new Circle();  
    delete shapePtr;                 
    return 0;
}
