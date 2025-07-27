#include<iostream>
#include<string>
using namespace std;
class Student {
private:
    string name;
    int age;
public:
    Student() {
        name = "";
        age = 0;
    }
    void displayStudentDetails() 
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    void setDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age; 
        cin.ignore();
    }
};
int main() {
    Student studentArray[3];  
    cout << "Enter details of 3 students:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        studentArray[i].setDetails();
    }
    cout << "Displaying student details:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": ";
        studentArray[i].displayStudentDetails();
    }
    return 0;
}
