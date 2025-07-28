/*What are different ios functions used in stream I/O? How they are different from manipulators?
Write a program to store and retrieve the information of patient (Patient_ID, name, address, age and
type) in hospital management system.*/
#include <iostream>
#include <fstream>
using namespace std;
class Patient {
private:
int patientID;
char name[50];
char address[100];
int age;
char type[30];
public:
void input() {
cout << "Enter Patient ID: ";
cin >> patientID;
cin.ignore();
cout << "Enter Name: ";
cin.getline(name, 50);
cout << "Enter Address: ";
cin.getline(address, 100);
cout << "Enter Age: ";
cin >> age;
cin.ignore();
cout << "Enter Patient Type (Inpatient/Outpatient): ";
cin.getline(type, 30);
}
void display() const {
cout << "Patient ID: " << patientID << "\n"
<< "Name: " << name << "\n"
<< "Address: " << address << "\n"
<< "Age: " << age << "\n"
<< "Type: " << type << "\n"
<< "-----------------------------\n";
}
void writeToFile(ofstream& fout) {
fout.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void readFromFile(ifstream& fin) {
fin.read(reinterpret_cast<char*>(this), sizeof(*this));
}
};
int main() {
int n;
cout << "Enter number of patients to store: ";
cin >> n;
cin.ignore();
ofstream fout("patients.dat", ios::binary | ios::app);
if (!fout) {
cerr << "Error opening file for writing!\n";
return 1;
}
for (int i = 0; i < n; i++) {
cout << "\nEnter details for patient " << (i + 1) << ":\n";
Patient p;
p.input();
p.writeToFile(fout);
}
fout.close();
ifstream fin("patients.dat", ios::binary);
if (!fin) {
cerr << "Error opening file for reading!\n";
return 1;
}
cout << "\n---- Patient Records ----\n";
Patient p;
while (fin.read(reinterpret_cast<char*>(&p), sizeof(p))) {
p.display();
}
fin.close();
return 0;
}
