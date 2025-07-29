#include<iostream>
#include <string>
using namespace std;
class Employee {
private:
string name;
int age;
public:
Employee(string n, int a) {
name = n;
age = a;
}
Employee(const Employee& c) {
name = c.name;
age = c.age;

}
void display() {
cout<< "Name: " << name << endl;
cout<< "Age: " << age << endl;
}
};
int main() {
string name;
int age;
cout << "Enter employee name: ";
getline(cin, name);
cout << "Enter employee age: ";
cin >> age;
Employee emp1(name, age);
cout << "\nOriginal Employee:\n";
emp1.display();
Employee emp2 = emp1;
cout << "\nCopied Employee:\n";
emp2.display();
return 0;
}

