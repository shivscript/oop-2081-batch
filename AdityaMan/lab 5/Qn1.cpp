#include<iostream>
using namespace std;
class complex{
int real, img;
public:
complex(int r=0,int i=0): real(r),img(i){}
friend complex operator +(complex c1, complex c2);
void input(){
cout<<"Enter a Complex Number"<<endl;
cout<<"real: ";
cin>>real;
cout<<"Imaginary: ";
cin>>img;
}
void display(){
cout<<real<<"+"<<img<<"i"<<endl;
}
};
complex operator +(complex c1, complex c2){
complex temp;
temp.real=c1.real+c2.real;
temp.img=c1.img+c2.img;
return temp;
}
int main(){
complex c1, c2, c3;
c1.input();
c2.input();
cout<<"The first complex number: ";
c1.display();
cout<<"The second complex number: ";
c2.display();
c3= c1+c2;
cout<<"Sum is: ";
c3.display();
}
