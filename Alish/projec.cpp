#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore(); // flush input buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;
    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

void displayAll() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }
    cout << "All Student Records:\n";
    for (const auto& s : students) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;
    for (const auto& s : students) {
        if (s.roll == roll) {
            cout << "Student Found:\n";
            cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << endl;
            return;
        }
    }
    cout << "Student Not Found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found.\n";
}

void updateStudent() {
    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;
    for (auto& s : students) {
        if (s.roll == roll) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, s.name);
            cout << "Enter New Marks: ";
            cin >> s.marks;
            cout << "Student Updated Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: cout << "Exiting Program. Goodbye!\n"; break;
            default: cout << "Invalid Choice. Try Again!\n";
        }
    } while (choice != 6);

    return 0;
}