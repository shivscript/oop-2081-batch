#include<iostream>
#include<string>
using namespace std;

class Employee {
private:
    int age;
    string name;

public:
    Employee(int ag, string n) {
        age = ag;
        name = n;
    }

    Employee(const Employee &a) {
        name = a.name;
        age = a.age;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Employee e(20, "Ankit");
    Employee e1 = e;
    e.display();
    e1.display();
    return 0;
}
