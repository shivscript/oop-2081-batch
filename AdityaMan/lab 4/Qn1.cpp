#include <iostream>
using namespace std;
class Shape{
public:
    void display(){
    cout<<"This is a Shape"<<endl;
}};
class Circle:public Shape{
    public:
    void draw(){
    cout<<"Drawing a Circle"<<endl;
    }};
int main(){
    Circle c;
    c.display();
    c.draw();
    return 0;
}
