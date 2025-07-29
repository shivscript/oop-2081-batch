/*Write a program to create an array of five Employee objects, each with name and salary. Display
the employee with the highest salary.*/
#include <iostream>
using namespace std;
class Employee {
private:
string name;
float salary;
public:
void input() {
cout << "Enter employee name: ";
cin.ignore();
getline(cin, name);
cout << "Enter salary: ";
cin >> salary;
}
void display() const {
cout << "Name: " << name << ", Salary: Rs. " << salary << endl;
}
float getSalary() const {
return salary;
}
};
int main() {
Employee emp[5];
int highestIndex = 0;
for (int i = 0; i < 5; i++) {
cout << "\nEnter Details for Employee " << i + 1 << ":" << endl;
emp[i].input();
if (emp[i].getSalary() > emp[highestIndex].getSalary()) {
highestIndex = i;
}
}
cout << "\nEmployee with Highest Salary: " << endl;
emp[highestIndex].display();
return 0;
}
