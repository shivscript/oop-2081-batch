#include<iostream>
#include<string>
using namespace std;
class Book {
    string title;
    string author;
    int year;
    public:
    Book()
    {
        title=" ";
        author=" ";
        year=0;
    }
    Book(string a, string b, int c)
    {
        title=a;
        author=b;
        year=c;
    }
    void display()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Year: "<<year<<endl;
    }
};
int main()
{
    Book b1;
    cout<<"Display with default constructor: "<<endl;
    b1.display();
    Book b2("Muna_Madan","Laxmi_Parsad_Devkota",1999);
    cout<<"Display with parametetized constructor: "<<endl;
    b2.display();
    return 0;
}