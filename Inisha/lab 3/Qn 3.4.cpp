#include <iostream>
#include <string>
using namespace std;
class Book {
private:
string title;
public:
Book(string t) {
title = t;
cout << "Book \"" << title << "\" is created.\n";
}
~Book() {
cout << "Book \"" << title << "\" is destroyed.\n";
}
};
int main() {
string t;
cout<<"Enter title: ";
getline(cin,t);
Book b1(t);
return 0;
}

