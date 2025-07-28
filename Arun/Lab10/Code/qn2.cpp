/*Why use file handling? Write a program in a file of student to add the record, list the record,
search by roll number and delete the record.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {
public:
    int roll;
    string name;
    float marks;
    void input() {
        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
    }
    void display() const {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};
void addRecord() {
    Student s;
    ofstream fout("student.txt", ios::app);
    s.input();
    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Record added successfully!\n";
}
void listRecords() {
    Student s;
    ifstream fin("student.txt");
    while (fin.read((char*)&s, sizeof(s))) {
        s.display();
    }
    fin.close();
}
void searchRecord(int roll_no) {
    Student s;
    bool found = false;
    ifstream fin("student.txt");
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.roll == roll_no) {
            cout << "Record found:\n";
            s.display();
            found = true;
            break;
        }
    }
    fin.close();
    if (!found)
        cout << "Record not found!\n";
}
void deleteRecord(int roll_no) {
    Student s;
    ifstream fin("student.txt");
    ofstream fout("temp.txt");

    bool found = false;
    while (fin.read((char*)&s, sizeof(s))) {
        if (s.roll != roll_no) {
            fout.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }

    fin.close();
    fout.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}
int main() {
    int choice, roll_no;
    do {
        cout << "\n1. Add Record\n2. List Records\n3. Search Record\n4. Delete Record\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: listRecords(); break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll_no;
                searchRecord(roll_no);
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> roll_no;
                deleteRecord(roll_no);
                break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
