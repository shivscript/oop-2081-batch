#include<iostream>
#include<string>
using namespace std;
class Book {
private:
    string title;
public:
    Book(string t) {
        title = t;
        cout << "Book \"" << title << "\" is created." << endl;
    }
    ~Book() {
        cout << "Book \"" << title << "\" is destroyed." << endl;
    }
};
int main() 
    {
    Book b1("C++ Fundamentals");
    return 0; 
}
