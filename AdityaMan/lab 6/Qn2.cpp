#include<iostream>
using namespace std;
class shape {
public:
virtual ~shape() {
cout << "Destructor of class shape." << endl;
}
};
class circle : public shape {
public:
circle() {
cout << "Constructor in class circle." << endl;
}
~circle() {
cout << "Destructor in class circle." << endl;
5
}
};
int main() {
shape* s = new circle();
delete s;
return 0;
}