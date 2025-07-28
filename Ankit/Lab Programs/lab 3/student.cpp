#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
public:
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void displayStudentDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student studentArray[3] = {
        Student("ankit", 20),
        Student("hari", 21),
        Student("ram", 22)
    };

    for (int i = 0; i < 3; ++i) {
        studentArray[i].displayStudentDetails();
    }

    return 0;
}
