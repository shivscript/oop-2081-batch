#include<iostream>
using namespace std;
class complex{
    float real, imz;
    public:
    complex()
    {
        real=0;
        imz=0;
    }
    complex (float a, float b)
    {
        real=a;
        imz=b;
    }
    complex operator+(complex &obj)
    {
        complex temp;
        temp.real=this->real+obj.real;
        temp.imz=this->imz+obj.imz;
        return temp;
    }
    void display()
    {
        cout<<"Result: "<<real<<"+"<<imz<<"i";
    }
};
int main()
{
    complex c1(1.56,8.94), c2(45.5,96.1),c3;
    c3=c1+c2;
    c3.display();
    return 0;
}