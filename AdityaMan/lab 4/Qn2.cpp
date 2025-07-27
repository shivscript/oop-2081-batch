#include <iostream>
using namespace std;
class Person {
public:
void name() {
cout << "Name: Ram" << endl;
}};
class Employee {
public:
void role() {
cout << "Role: Full-time Employee" << endl;
}};
class Manager: public Person, public Employee {
public:
void details() {
cout << "Employee Details:" << endl;
name();
role();
}};
int main() {
Manager m;
m.details();
}
