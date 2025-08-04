#include <iostream>
#include<string>
using namespace std;
class Car{
string brand, model;
int year;
public:
void setData(){
cout<<"Enter brand: ";
getline(cin,brand);
cout<<"Enter model: ";
getline(cin,model);
cout<<"Enter year: ";
cin>>year;
}
void display(){
cout<<"\n****CAR DETAILS****\n";
cout<<"BRAND: "<<brand<<endl;
cout<<"MODEL: "<<model<<endl;
cout<<"YEAR: "<<year<<endl;
}
};
int main()
{
Car c;
c.setData();
c.display();
return 0;
}

