#include <iostream> 
using namespace std; 
struct StudentStruct {
int roll; 
float marks; 
char grade;
};
union StudentUnion { 
    int roll;
    float marks; 
    char grade;
};
int main() { StudentStruct s1; StudentUnion u1;
cout << "Size of structure: " << sizeof(s1) << " bytes" << endl; 
cout << "Size of union: " << sizeof(u1) << " bytes" << endl; 
s1.roll = 101;
s1.marks = 85.5; 
s1.grade = 'A';
cout << "\nStructure values:" << endl; 
cout << "Roll: " << s1.roll << endl; 
cout << "Marks: " << s1.marks << endl; 
cout << "Grade: " << s1.grade << endl;
u1.roll = 101;
cout << "\nUnion value after setting roll: " << u1.roll << endl;
 
u1.marks = 85.5;
cout << "Union value after setting marks: " << u1.marks << endl; 
u1.grade = 'A';
cout << "Union value after setting grade: " << u1.grade << endl;
cout << "\nAccessing all union members (may show unexpected values):" << endl; 
cout << "Roll: " << u1.roll << endl;
cout << "Marks: " << u1.marks << endl; 
cout << "Grade: " << u1.grade << endl; 
return 0;
}
