#include<iostream>
#include<string>
using namespace std;
class Employee {
    string name;
    int age;
public:
    void setdata(string a, int b) {
        name = a;
        age = b;
    }
    Employee(const Employee &obj) {
        name = obj.name;
        age = obj.age;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    Employee() {}
};
int main() {
    Employee e1;
    e1.setdata("Ramesh", 50);
    cout << "Original data: " << endl;
    e1.display();
    Employee e2 = e1; 
    cout << "Copied data: " << endl;
    e2.display();
    return 0;
}
