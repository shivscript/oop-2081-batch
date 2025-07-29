#include <iostream>
using namespace std;
class Person {
public:
void name() {
cout << "Name: Inisha Mali" << endl;
}
};
class Employee {
public:
void role() {
cout << "Role: Manager" << endl;
}
};
class Manager : public Person, public Employee {
public:
void details() {
cout << "Manager Details:" << endl;
name();
role();
} };
int main() {
Manager m;
m.details();
return 0;
}

