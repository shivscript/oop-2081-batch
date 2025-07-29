#include <iostream>
using namespace std;
class Student {
string name;
int age;
public:
Student(string n, int a) : name(n), age(a) {}
void display () {
cout << "Name: " << name << ", Age: " << age << endl;
}
};
int main() {
Student* s[3];
for (int i = 0; i < 3; i++) {
string name;
int age;
cout << "Enter name of student " << (i + 1) << ": ";
getline(cin, name);
cout << "Enter age of student " << (i + 1) << ": ";
cin >> age;
cin.ignore();
s[i] = new Student(name, age);
}
cout << "\nStudent details:\n";
for (int i = 0; i < 3; i++) {
s[i]->display();
delete s[i];
}

return 0;
}

