#include<iostream>
using namespace std;
class shape {
    public:
    void display()
    {
        cout<<"Displayed in base class."<<endl;
    }
};
class circle:public shape {
    public:
    void draw()
    {
        cout<<"Displayed in derived class."<<endl;
    }
};
int main() {
    circle c;
    c.display();
    c.draw();
    return 0;
}