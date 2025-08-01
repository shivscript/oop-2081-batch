#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_USERS = 100;
const int MAX_PROGRAMS = 50;
const int MAX_SEMESTERS = 8;
const int MAX_SUBJECTS = 6;

class User {
protected:
    string name;
    int id;
public:
    User() : name(""), id(-1) {}
    void setInfo(string n, int i) {
        name = n;
        id = i;
    }
    string getName() { return name; }
    int getId() { return id; }
    virtual void display() = 0;
};

class Subject {
public:
    string name;
    int marks;
    Subject() : name(""), marks(-1) {}
};

class Semester {
public:
    Subject subjects[MAX_SUBJECTS];
    int subjectCount;
    Semester() : subjectCount(0) {}
};

class Student : public User {
    string enrolledProgram;
    bool hasProgram;
    Semester semesters[MAX_SEMESTERS];
    int semesterCount;
public:
    Student() : enrolledProgram(""), hasProgram(false), semesterCount(0) {}
    void display() {
        cout << "Student Name: " << name << ", ID: " << id << endl;
        if (hasProgram) {
            cout << "Enrolled Program: " << enrolledProgram << endl;
            double totalMarks = 0;
            int totalSubjects = 0;
            for (int i = 0; i < semesterCount; i++) {
                double semTotalMarks = 0;
                int semSubjectCount = semesters[i].subjectCount;
                cout << "Semester " << (i + 1) << ":\n";
                for (int j = 0; j < semSubjectCount; j++) {
                    cout << "  Subject: " << semesters[i].subjects[j].name
                         << ", Marks: " << semesters[i].subjects[j].marks
                         << " (" << (semesters[i].subjects[j].marks >= 40 ? "Pass" : "Fail") << ")" << endl;
                    semTotalMarks += semesters[i].subjects[j].marks;
                    totalMarks += semesters[i].subjects[j].marks;
                    totalSubjects++;
                }
                double semAvg = semSubjectCount > 0 ? semTotalMarks / semSubjectCount : 0;
                cout << "  Semester Average Marks: " << semAvg << endl;
            }
            double result = totalSubjects > 0 ? totalMarks / totalSubjects : 0;
            cout << "Overall Result (Average Marks): " << result << endl;
        } else {
            cout << "No program enrolled.\n";
        }
    }
    bool enrollProgram(string p) {
        if (!hasProgram) {
            enrolledProgram = p;
            hasProgram = true;
            return true;
        }
        return false;
    }
    bool addSemester() {
        if (semesterCount < MAX_SEMESTERS) {
            semesters[semesterCount].subjectCount = 0;
            semesterCount++;
            return true;
        }
        return false;
    }
    bool addSubject(int semIndex, string subjName, int m) {
        if (hasProgram && semIndex < semesterCount && m >= 0 && m <= 100) {
            Semester& sem = semesters[semIndex];
            if (sem.subjectCount < MAX_SUBJECTS) {
                sem.subjects[sem.subjectCount].name = subjName;
                sem.subjects[sem.subjectCount].marks = m;
                sem.subjectCount++;
                return true;
            }
        }
        return false;
    }
    bool updateMarks(int semIndex, string subjName, int m) {
        if (hasProgram && semIndex < semesterCount && m >= 0 && m <= 100) {
            Semester& sem = semesters[semIndex];
            for (int i = 0; i < sem.subjectCount; i++) {
                if (sem.subjects[i].name == subjName) {
                    sem.subjects[i].marks = m;
                    return true;
                }
            }
        }
        return false;
    }
    bool hasEnrolledProgram() { return hasProgram; }
    string getProgram() { return enrolledProgram; }
    double getResult() {
        double totalMarks = 0;
        int totalSubjects = 0;
        for (int i = 0; i < semesterCount; i++) {
            for (int j = 0; j < semesters[i].subjectCount; j++) {
                totalMarks += semesters[i].subjects[j].marks;
                totalSubjects++;
            }
        }
        return totalSubjects > 0 ? totalMarks / totalSubjects : 0;
    }
    int getSemesterCount() { return semesterCount; }
    Semester* getSemesters() { return semesters; }
};

Student students[MAX_USERS];
int studentCount = 0;

bool isValidName(string name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == ' ')) {
            return false;
        }
    }
    return true;
}

bool isUniqueID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getId() == id) return false;
    }
    return true;
}

int findStudentByName(string sname) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == sname)
            return i;
    }
    return -1;
}

void deleteStudent() {
    cout << "Enter student name to delete: ";
    string name;
    getline(cin, name);
    int idx = findStudentByName(name);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }
    for (int i = idx; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    cout << "Student deleted successfully.\n";
    //saveToFile();
}

void saveToFile() {
    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        outFile << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            outFile << students[i].getName() << endl;
            outFile << students[i].getId() << endl;
            outFile << students[i].hasEnrolledProgram() << endl;
            if (students[i].hasEnrolledProgram()) {
                outFile << students[i].getProgram() << endl;
                outFile << students[i].getSemesterCount() << endl;
                for (int j = 0; j < students[i].getSemesterCount(); j++) {
                    Semester sem = students[i].getSemesters()[j];
                    outFile << sem.subjectCount << endl;
                    for (int k = 0; k < sem.subjectCount; k++) {
                        outFile << sem.subjects[k].name << endl;
                        outFile << sem.subjects[k].marks << endl;
                    }
                }
            }
        }
        outFile.close();
        cout << "Data saved to file.\n";
    } else {
        cout << "Unable to open file for saving.\n";
    }
}

void loadFromFile() {
    ifstream inFile("students.txt");
    if (inFile.is_open()) {
        studentCount = 0;
        int count;
        inFile >> count;
        inFile.ignore();
        for (int i = 0; i < count && i < MAX_USERS; i++) {
            string name, program, subjName;
            int id, semCount, subjCount, marks;
            bool hasProgram;
            getline(inFile, name);
            inFile >> id >> hasProgram;
            inFile.ignore();
            students[i].setInfo(name, id);
            if (hasProgram) {
                getline(inFile, program);
                students[i].enrollProgram(program);
                inFile >> semCount;
                inFile.ignore();
                for (int j = 0; j < semCount && j < MAX_SEMESTERS; j++) {
                    students[i].addSemester();
                    inFile >> subjCount;
                    inFile.ignore();
                    for (int k = 0; k < subjCount && k < MAX_SUBJECTS; k++) {
                        getline(inFile, subjName);
                        inFile >> marks;
                        inFile.ignore();
                        students[i].addSubject(j, subjName, marks);
                    }
                }
            }
            studentCount++;
        }
        inFile.close();
        cout << "Data loaded from file.\n";
    } else {
        cout << "No existing data file found or access denied.\n";
    }
}

void generateReports() {
    cout << "\n--- Reports ---\n";
    string programs[MAX_PROGRAMS];
    int programCounts[MAX_PROGRAMS] = {0};
    double programMarksSum[MAX_PROGRAMS] = {0};
    int uniqueProgramCount = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].hasEnrolledProgram()) {
            string program = students[i].getProgram();
            int j;
            for (j = 0; j < uniqueProgramCount; j++) {
                if (programs[j] == program) {
                    programCounts[j]++;
                    programMarksSum[j] += students[i].getResult();
                    break;
                }
            }
            if (j == uniqueProgramCount && uniqueProgramCount < MAX_PROGRAMS) {
                programs[uniqueProgramCount] = program;
                programCounts[uniqueProgramCount] = 1;
                programMarksSum[uniqueProgramCount] = students[i].getResult();
                uniqueProgramCount++;
            }
        }
    }

    cout << "1. Number of students per program:\n";
    if (uniqueProgramCount == 0) {
        cout << "No programs enrolled.\n";
    } else {
        for (int i = 0; i < uniqueProgramCount; i++) {
            cout << "Program: " << programs[i] << ", Students: " << programCounts[i] << endl;
        }
    }

    cout << "\n2. Average marks per program:\n";
    if (uniqueProgramCount == 0) {
        cout << "No programs enrolled.\n";
    } else {
        for (int i = 0; i < uniqueProgramCount; i++) {
            double avg = programCounts[i] > 0 ? programMarksSum[i] / programCounts[i] : 0;
            cout << "Program: " << programs[i] << ", Average Marks: " << avg << endl;
        }
    }

    cout << "\n3. Enter threshold for marks filtering: ";
    int threshold;
    cin >> threshold;
    cin.ignore();
    cout << "\nStudents with average marks above " << threshold << ":\n";
    bool foundAbove = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].hasEnrolledProgram() && students[i].getResult() > threshold) {
            students[i].display();
            cout << endl;
            foundAbove = true;
        }
    }
    if (!foundAbove) cout << "No students found.\n";

    cout << "\nStudents with average marks below or equal to " << threshold << ":\n";
    bool foundBelow = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].hasEnrolledProgram() && students[i].getResult() <= threshold) {
            students[i].display();
            cout << endl;
            foundBelow = true;
        }
    }
    if (!foundBelow) cout << "No students found.\n";
}

void sortAndDisplayStudents() {
    cout << "Sort by:\n1. Name\n2. ID\n3. Average Marks\nEnter choice: ";
    int sortChoice;
    cin >> sortChoice;
    cin.ignore();

    Student sortedStudents[MAX_USERS];
    for (int i = 0; i < studentCount; i++) {
        sortedStudents[i] = students[i];
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            bool swapNeeded = false;
            if (sortChoice == 1) {
                swapNeeded = sortedStudents[j].getName() > sortedStudents[j + 1].getName();
            } else if (sortChoice == 2) {
                swapNeeded = sortedStudents[j].getId() > sortedStudents[j + 1].getId();
            } else if (sortChoice == 3) {
                if (!sortedStudents[j].hasEnrolledProgram() && sortedStudents[j + 1].hasEnrolledProgram()) {
                    swapNeeded = true;
                } else if (sortedStudents[j].hasEnrolledProgram() && sortedStudents[j + 1].hasEnrolledProgram()) {
                    swapNeeded = sortedStudents[j].getResult() > sortedStudents[j + 1].getResult();
                }
            } else {
                cout << "Invalid sort choice.\n";
                return;
            }
            if (swapNeeded) {
                Student temp = sortedStudents[j];
                sortedStudents[j] = sortedStudents[j + 1];
                sortedStudents[j + 1] = temp;
            }
        }
    }

    cout << "\n--- Sorted Students ---\n";
    for (int i = 0; i < studentCount; i++) {
        sortedStudents[i].display();
        cout << endl;
    }
}

int main() {
    loadFromFile();
    int choice;
    string name;
    cout << "Welcome to University Management Portal\n";
    cout << "Who are you?\n1. Student\n2. Admin\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter your name: ";
        getline(cin, name);
        int idx = findStudentByName(name);
        if (idx == -1) {
            cout << "Student not found.\n";
            return 0;
        }
        students[idx].display();
    } else if (choice == 2) {
        while (true) {
            cout << "\n1. Add Student with Program and Subjects\n2. View All Students\n3. Update Student Marks\n4. Delete Student\n5. Save to File\n6. Generate Reports\n7. Sort and View Students\n8. Exit\nEnter choice: ";
            int adminChoice;
            cin >> adminChoice;
            cin.ignore();

            if (adminChoice == 1) {
                cout << "Enter student name: ";
                getline(cin, name);
                if (!isValidName(name)) {
                    cout << "Invalid name. Use alphanumeric characters and spaces only.\n";
                    continue;
                }
                cout << "Enter student ID: ";
                int id;
                cin >> id;
                cin.ignore();
                if (!isUniqueID(id)) {
                    cout << "ID already exists. Please use a unique ID.\n";
                    continue;
                }
                cout << "Enter program name: ";
                string program;
                getline(cin, program);
                students[studentCount].setInfo(name, id);
                if (!program.empty()) {
                    if (!students[studentCount].enrollProgram(program)) {
                        cout << "Failed to enroll program.\n";
                        continue;
                    }
                    cout << "Enter number of completed semesters (0-" << MAX_SEMESTERS << "): ";
                    int semCount;
                    cin >> semCount;
                    cin.ignore();
                    if (semCount < 0 || semCount > MAX_SEMESTERS) {
                        cout << "Invalid semester count.\n";
                        continue;
                    }
                    for (int i = 0; i < semCount; i++) {
                        if (!students[studentCount].addSemester()) {
                            cout << "Failed to add semester.\n";
                            break;
                        }
                        cout << "Enter number of subjects for semester " << (i + 1) << " (0-" << MAX_SUBJECTS << "): ";
                        int subjCount;
                        cin >> subjCount;
                        cin.ignore();
                        if (subjCount < 0 || subjCount > MAX_SUBJECTS) {
                            cout << "Invalid subject count.\n";
                            continue;
                        }
                        for (int j = 0; j < subjCount; j++) {
                            cout << "Enter subject name: ";
                            string subjName;
                            getline(cin, subjName);
                            cout << "Enter marks for " << subjName << " (0-100): ";
                            int marks;
                            cin >> marks;
                            cin.ignore();
                            if (!students[studentCount].addSubject(i, subjName, marks)) {
                                cout << "Failed to add subject. Marks must be 0-100 or semester/subject limit reached.\n";
                            }
                        }
                    }
                }
                studentCount++;
                cout << "Student added.\n";
            } else if (adminChoice == 2) {
                cout << "\n--- Students ---\n";
                for (int i = 0; i < studentCount; i++) {
                    students[i].display();
                    cout << endl;
                }
            } else if (adminChoice == 3) {
                cout << "Enter student name: ";
                getline(cin, name);
                int idx = findStudentByName(name);
                if (idx == -1) {
                    cout << "Student not found.\n";
                    continue;
                }
                if (students[idx].hasEnrolledProgram()) {
                    cout << "Enter semester number (1-" << students[idx].getSemesterCount() << "): ";
                    int semNum;
                    cin >> semNum;
                    cin.ignore();
                    if (semNum < 1 || semNum > students[idx].getSemesterCount()) {
                        cout << "Invalid semester number.\n";
                        continue;
                    }
                    cout << "Enter subject name: ";
                    string subjName;
                    getline(cin, subjName);
                    cout << "Enter new marks (0-100): ";
                    int newMarks;
                    cin >> newMarks;
                    cin.ignore();
                    if (students[idx].updateMarks(semNum - 1, subjName, newMarks)) {
                        cout << "Marks updated successfully.\n";
                    } else {
                        cout << "Failed to update marks. Check subject name or ensure marks are 0-100.\n";
                    }
                } else {
                    cout << "Student has no enrolled program.\n";
                }
            } else if (adminChoice == 4) {
                deleteStudent();
            } else if (adminChoice == 5) {
                saveToFile();
            } else if (adminChoice == 6) {
                generateReports();
            } else if (adminChoice == 7) {
                sortAndDisplayStudents();
            } else if (adminChoice == 8) {
                saveToFile();
                break;
            } else {
                cout << "Invalid choice.\n";
            }
        }
    } else {
        cout << "Invalid role.\n";
    }
    return 0;
}
