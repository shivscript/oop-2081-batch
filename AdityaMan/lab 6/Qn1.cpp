#include<iostream>
using namespace std;
class base{
public:
virtual void display () {
cout<<"Displayed in base class";
}
};
class derived : public base {
public:
void display() override {
cout<<"Displayed in derived class";
}
};
int main() {
base *b;
derived d;
b=&d;
b->display();
return 0;
}