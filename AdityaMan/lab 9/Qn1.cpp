#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    string course;
};
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll number: ";
        cin >> s.roll;
        cin.ignore();
        cout << "Name: ";
        getline(cin, s.name);
        cout << "Age: ";
        cin >> s.age;
        cin.ignore();
        cout << "Course: ";
        getline(cin, s.course);
        students.push_back(s);
    }

    ofstream fout("students.txt");
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return 1;
    }
    for (const auto& s : students) {
        fout << s.roll << "," << s.name << "," << s.age << "," << s.course << endl;
    }
    fout.close();

    cout << "\n--- Student Details ---\n";
    for (const auto& s : students) {
        cout << "Roll: " << s.roll << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course: " << s.course << endl;
        cout << "----------------------\n";
    }
    return 0;
}
