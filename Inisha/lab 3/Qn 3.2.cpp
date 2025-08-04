#include <iostream>
#include<string>
using namespace std;
class Book{
string title, author;
int year;
public:
Book(){
title="";
author="";
year=0;
}
Book(string t, string a,int y){
title=t;
author=a;
year=y;
}

void display(){
cout<<"\n****BOOK DETAILS****\n";
cout<<"TITLE: "<<title<<endl;
cout<<"AUTHOR: "<<author<<endl;
cout<<"YEAR: "<<year<<endl;
}
};
int main()
{
cout<<"DEFAULT CONSTRUCTOR";
Book b;
b.display();
string t,a;
int y;
cout<<"Enter title: ";
getline(cin,t);
cout<<"Enter author: ";
getline(cin,a);
cout<<"Enter year: ";
cin>>y;
cin.ignore();
Book c(t,a,y);
c.display();
return 0;
}

