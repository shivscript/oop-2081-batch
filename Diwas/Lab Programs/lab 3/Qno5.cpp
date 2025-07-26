#include<iostream>
using namespace std;
class Rectangle {
    int length;
    int width;
    public:
    void setdata()
    {
        cout<<"Length: ";
        cin>>length;
        cout<<"Width: ";
        cin>>width;
    }
    void displaydata()
    {
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
    }
    Rectangle()
    {
        length=0;
        width=0;
    }
    void calculateArea()
    {
        int area=length*width;
        cout<<"Area is: "<<area<<endl;
    }
    void doubleDimensions(Rectangle &rect)
    {
        rect.length=rect.length*2;
        rect.width=rect.width*2;
    }
};
int main()
{
    Rectangle r1;
    cout<<"Enter input: "<<endl;
    r1.setdata();
    cout<<"Area calculation: "<<endl;
    r1.calculateArea();
    cout<<"Double dimensions: "<<endl;
    r1.doubleDimensions(r1);
    r1.displaydata();
    cout<<"Area calculation: "<<endl;
    r1.calculateArea();
    return 0;
}