/*Write a program to create a class that uses a copy constructor to copy data from one object to
another.*/
#include <iostream>
using namespace std;
class Student {
private:
int roll;
string name;
public:
Student(int r, string n) {
roll = r;
name = n;
cout << "Parameterized constructor called." << endl;
}
Student(const Student &s) {
roll = s.roll;
name = s.name;
cout << "Copy constructor called." << endl;
}
void display() {
cout << "Name: " << name << ", Roll Number: " << roll << endl;
}
};
int main() {
int r;
string n;
cout << "Enter student name: ";
getline(cin, n);
cout << "Enter roll number: ";
cin >> r;
cout << "\nCreating Original Object" << endl;
Student s1(r, n);
cout << "\nCreating Copy Using Copy Constructor " << endl;
Student s2 = s1;
cout << "\n--- Displaying Objects ---" << endl;
cout << "Original Object: ";
s1.display();
cout << "Copied Object: ";
s2.display();
return 0;
}
