#include<iostream> 
#include<string> 
using namespace std; 
struct student {
int roll;
char name[25]; float marks;
};
int main()
{
student s[3];
for(int i = 0; i < 3; i++) {
cout << "Enter the details of students:" << (i + 1) << endl; 
cout << "Roll number: ";	
cin >> s[i].roll;
cout << "Name: "; cin>>s[i].name; cout << "Marks: "; cin >> s[i].marks;
}
cout << "---Student Details---"<<endl; 
for(int i = 0; i < 3; i++) { 
    cout<<"Student"<<i+1<<":";
    cout<< "Roll: " << s[i].roll << ", Name: " << s[i].name << ", Marks: " << s[i].marks << endl;
}
return 0;
}
