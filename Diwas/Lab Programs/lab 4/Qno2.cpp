#include<iostream>
using namespace std;
class Person {
    public:
    void pdisplay(){
        cout<<"Person name: Mukesh"<<endl;
    }
};
class Employee {
    public:
    void edisplay(){
        cout<<"Employee post: CEO"<<endl;
    }
};
class Manager : public Person, public Employee {
    public:
    void mdisplay(){
        cout<<"Details: "<<endl;
    }
};
int main()
{
    Manager a;
    a.mdisplay();
    a.pdisplay();
    a.edisplay();
}