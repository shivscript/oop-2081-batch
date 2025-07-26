#include<iostream>
#include<string>
using namespace std;
class Car {
    string brand;
    string model;
    int year;
    public:
    void setdata()
    {
        cout<<"Brand name: ";
        getline(cin,brand);
        cout<<"Model: ";
        getline(cin,model);
        cout<<"Year: ";
        cin>>year;
    }
    void displaydata()
    {
        cout<<"Brand name: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }
};
int main()
{
    Car car1;
    cout<<"Enter the details: "<<endl;
    car1.setdata();
    //cout<<"Displaying datamembers directly"<<endl;
    //cout<<"Brand name: "<<car1.brand<<endl;
    //cout<<"Model: "<<car1.model<<endl;
    //cout<<"Year: "<<car1.year<<endl;
        // This is the wrong way and won't execute with this code.
    cout<<"Displaying datamembers using member fucntion. "<<endl;
    car1.displaydata();
    return 0;
}