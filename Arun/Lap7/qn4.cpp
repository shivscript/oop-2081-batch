/*Create a base class Person with a virtual method show().
 Create another base class Employee with a virtual method show(). 
 Create a derived class Manager that inherits from both Person and Employee, and
overrides the show() method.  Implement a main() function to demonstrate the usage of these classes.*/
#include <iostream>
using namespace std;
class Person {
public:
    virtual void show() {
        cout << "Person details" << endl;
    }
    virtual ~Person() {}
};
class Employee {
public:
    virtual void show() {
        cout << "Employee details" << endl;
    }
    virtual ~Employee() {}
};
class Manager : public Person, public Employee {
public:
    void show() override {
        cout << "Manager details: combines Person and Employee roles" << endl;
    }
};

int main() {
    Manager m;
    m.show();
    Person* p = &m;
    Employee* e = &m;

    cout << "\nAccess via Person pointer:\n";
    p->show();  
    cout << "\nAccess via Employee pointer:\n";
    e->show();  
    return 0;
}
